#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "esp_log.h"

#define UART_NUM UART_NUM_2
#define BUF_SIZE (1024)
#define RXD_PIN (GPIO_NUM_16)

static const char *TAG = "UART Example";

void uart_task(void *arg)
{
    uint8_t data[BUF_SIZE];
    while (1) {
        // read data from UART
        int length = uart_read_bytes(UART_NUM, data, BUF_SIZE, 20 / portTICK_RATE_MS);
        if (length > 0) {
            // print received data
            data[length] = '\0'; // null-terminate the data
            ESP_LOGI(TAG, "Received: '%s'", data);
        }
        vTaskDelay(100 / portTICK_RATE_MS);
    }
}

void app_main(void)
{
    // configure UART
    const uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };

    uart_param_config(UART_NUM, &uart_config);
    uart_set_pin(UART_NUM, UART_PIN_NO_CHANGE, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM, BUF_SIZE * 2, 0, 0, NULL, 0);

    // create a task to handle UART
    xTaskCreate(uart_task, "uart_task", 1024 * 2, NULL, configMAX_PRIORITIES, NULL);
}
