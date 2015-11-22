#ifndef MOCK_USART_H 
#define MOCK_USART_H 

#include <uart_handler.h>
#include <gmock/gmock.h>

extern "C" {
    void usart_set_baudrate_impl(uint32_t usart, uint32_t baud);
    void usart_set_databits_impl(uint32_t usart, uint32_t bits);
    void usart_set_stopbits_impl(uint32_t usart, uint32_t stopbits);
    void usart_set_parity_impl(uint32_t usart, uint32_t parity);
    void usart_set_mode_impl(uint32_t usart, uint32_t mode);
    void usart_set_flow_control_impl(uint32_t usart, uint32_t flowcontrol);
    void usart_enable_impl(uint32_t usart);
    uint16_t usart_recv_blocking_impl(uint32_t usart);

    void usart_set_baudrate(uint32_t usart, uint32_t baud);
    void usart_set_databits(uint32_t usart, uint32_t bits);
    void usart_set_stopbits(uint32_t usart, uint32_t stopbits);
    void usart_set_parity(uint32_t usart, uint32_t parity);
    void usart_set_mode(uint32_t usart, uint32_t mode);
    void usart_set_flow_control(uint32_t usart, uint32_t flowcontrol);
    void usart_enable(uint32_t usart);
    uint16_t usart_recv_blocking(uint32_t usart);
}

struct UsartInterface {
    virtual void usart_set_baudrate_invoke(uint32_t usart, uint32_t baud) const = 0;
    virtual void usart_set_databits_invoke(uint32_t usart, uint32_t bits) const = 0;
    virtual void usart_set_stopbits_invoke(uint32_t usart, uint32_t stopbits) const = 0;
    virtual void usart_set_parity_invoke(uint32_t usart, uint32_t parity) const = 0;
    virtual void usart_set_mode_invoke(uint32_t usart, uint32_t mode) const = 0;
    virtual void usart_set_flow_control_invoke(uint32_t usart, uint32_t flowcontrol) const = 0;
    virtual void usart_enable_invoke(uint32_t usart) const = 0;
    virtual uint16_t usart_recv_blocking_invoke(uint32_t usart) const = 0;
};

class MockUsart : public UsartInterface {
public:
    virtual ~MockUsart() {}
    MOCK_CONST_METHOD2(usart_set_baudrate_invoke, void(uint32_t usart, uint32_t baud));
    MOCK_CONST_METHOD2(usart_set_databits_invoke, void(uint32_t usart, uint32_t bits));
    MOCK_CONST_METHOD2(usart_set_stopbits_invoke, void(uint32_t usart, uint32_t stopbits));
    MOCK_CONST_METHOD2(usart_set_parity_invoke, void(uint32_t usart, uint32_t parity));
    MOCK_CONST_METHOD2(usart_set_mode_invoke, void(uint32_t usart, uint32_t mode));
    MOCK_CONST_METHOD2(usart_set_flow_control_invoke, void(uint32_t usart, uint32_t flowcontrol));
    MOCK_CONST_METHOD1(usart_enable_invoke, void(uint32_t usart));
    MOCK_CONST_METHOD1(usart_recv_blocking_invoke, uint16_t(uint32_t usart));
};

class RealUsart : public UsartInterface {
public:
    virtual ~RealUsart () {}
    void usart_set_baudrate_invoke(uint32_t usart, uint32_t baud) const;
    void usart_set_databits_invoke(uint32_t usart, uint32_t bits) const;
    void usart_set_stopbits_invoke(uint32_t usart, uint32_t stopbits) const;
    void usart_set_parity_invoke(uint32_t usart, uint32_t parity) const;
    void usart_set_mode_invoke(uint32_t usart, uint32_t mode) const;
    void usart_set_flow_control_invoke(uint32_t usart, uint32_t flowcontrol) const;
    void usart_enable_invoke(uint32_t usart) const;
    uint16_t usart_recv_blocking_invoke(uint32_t usart) const;
};

#endif /* MOCK_USART_H */
