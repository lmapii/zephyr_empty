
#include <zephyr/kernel.h>

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS 100

#define SW0_NODE DT_ALIAS(sw0)
#if !DT_NODE_HAS_STATUS(SW0_NODE, okay)
#error "Unsupported board: sw0 devicetree alias is not defined"
#endif
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(SW0_NODE, gpios);

#define LED0_NODE DT_ALIAS(led0)
#if !DT_NODE_HAS_STATUS(LED0_NODE, okay)
#error "Unsupported board: led0 devicetree alias is not defined"
#endif
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

void main(void)
{
    int rc;

    if (!device_is_ready(led.port) || !device_is_ready(button.port)) {
        return;
    }

    rc = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (rc < 0) {
        return;
    }

    rc = gpio_pin_configure_dt(&button, GPIO_INPUT);
    if (rc < 0) {
        return;
    }

    while (1) {
        bool val = gpio_pin_get_dt(&button);
        gpio_pin_set_dt(&led, val);
        k_msleep(SLEEP_TIME_MS);
    }
}
