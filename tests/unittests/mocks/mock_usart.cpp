#include <mock_usart.h>

extern MockUsart *mocked_usart;

void usart_set_baudrate_impl(uint32_t usart, uint32_t baud) {
    mocked_usart->usart_set_baudrate_invoke(usart, baud);
}

void usart_set_databits_impl(uint32_t usart, uint32_t bits) {
    mocked_usart->usart_set_databits_invoke(usart, bits);
}

void usart_set_stopbits_impl(uint32_t usart, uint32_t stopbits) {
    mocked_usart->usart_set_stopbits_invoke(usart, stopbits);
}

void usart_set_parity_impl(uint32_t usart, uint32_t parity) {
    mocked_usart->usart_set_parity_invoke(usart, parity);
}

void usart_set_mode_impl(uint32_t usart, uint32_t mode) {
    mocked_usart->usart_set_mode_invoke(usart, mode);
}

void usart_set_flow_control_impl(uint32_t usart, uint32_t flowcontrol) {
    mocked_usart->usart_set_flow_control_invoke(usart, flowcontrol);
}

void usart_enable_impl(uint32_t usart) {
    mocked_usart->usart_enable_invoke(usart);
}

uint16_t usart_recv_blocking_impl(uint32_t usart) {
    return mocked_usart->usart_recv_blocking_invoke(usart);
}

void usart_set_baudrate(uint32_t usart, uint32_t baud) __attribute__(( weak, alias ("usart_set_baudrate_impl") ));
void usart_set_databits(uint32_t usart, uint32_t bits) __attribute__(( weak, alias ("usart_set_databits_impl") ));
void usart_set_stopbits(uint32_t usart, uint32_t stopbits) __attribute__(( weak, alias ("usart_set_stopbits_impl") ));
void usart_set_parity(uint32_t usart, uint32_t parity) __attribute__(( weak, alias ("usart_set_parity_impl") ));
void usart_set_mode(uint32_t usart, uint32_t mode) __attribute__(( weak, alias ("usart_set_mode_impl") ));
void usart_set_flow_control(uint32_t usart, uint32_t flowcontrol) __attribute__(( weak, alias ("usart_set_flow_control_impl") ));
void usart_enable(uint32_t usart) __attribute__(( weak, alias ("usart_enable_impl") ));
uint16_t usart_recv_blocking(uint32_t usart) __attribute__(( weak, alias ("usart_recv_blocking_impl") ));


/******** RealUsart ********/

void RealUsart::usart_set_baudrate_invoke(uint32_t usart, uint32_t baud) const {
    usart_set_baudrate_impl(usart, baud);
}

void RealUsart::usart_set_databits_invoke(uint32_t usart, uint32_t bits) const {
    usart_set_databits_impl(usart, bits);
}

void RealUsart::usart_set_stopbits_invoke(uint32_t usart, uint32_t stopbits) const {
    usart_set_stopbits_invoke(usart, stopbits);
}

void RealUsart::usart_set_parity_invoke(uint32_t usart, uint32_t parity) const {
    usart_set_parity_impl(usart, parity);
}

void RealUsart::usart_set_mode_invoke(uint32_t usart, uint32_t mode) const {
    usart_set_mode_impl(usart, mode);
}

void RealUsart::usart_set_flow_control_invoke(uint32_t usart, uint32_t flowcontrol) const {
    usart_set_flow_control_impl(usart, flowcontrol);
}

void RealUsart::usart_enable_invoke(uint32_t usart) const {
    usart_enable_impl(usart);
}

uint16_t RealUsart::usart_recv_blocking_invoke(uint32_t usart) const {
    return usart_recv_blocking_impl(usart);
}

