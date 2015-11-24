#include "mocks/mock_usart.h"
#include <uart_handler.h>
#include <libopencm3/stm32/usart.h>  // to get USART2 defined
#include <gtest/gtest.h>

using ::testing::Return;

MockUsart *mocked_usart;

/***** Uart_Handler::get_rx_data() *****/

class GetRxData : public ::testing::Test {
protected:
    virtual void SetUp() {
        mocked_usart = new MockUsart();
    }

    virtual void TearDown() {
        delete mocked_usart;
    }
};


TEST_F(GetRxData, ReadZero) {
  Uart_Handler uart_handler;

  ON_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).WillByDefault(Return(0));
  EXPECT_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).Times(1);

  EXPECT_EQ(0, uart_handler.get_rx_data());
}

TEST_F(GetRxData, ReadPositive) {
  Uart_Handler uart_handler;

  ON_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).WillByDefault(Return(123));
  EXPECT_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).Times(1);

  EXPECT_EQ(123, uart_handler.get_rx_data());
}

TEST_F(GetRxData, ReadMaximal) {
  Uart_Handler uart_handler;

  ON_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).WillByDefault(Return(65535));
  EXPECT_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).Times(1);

  EXPECT_EQ(65535, uart_handler.get_rx_data());
}


/***** Uart_Handler::receive() *****/

class Receive : public ::testing::Test {
protected:
    virtual void SetUp() {
        mocked_usart = new MockUsart();
    }

    virtual void TearDown() {
        delete mocked_usart;
    }
};


TEST_F(Receive, ReceiveZero) {
    Uart_Handler uart_handler;

    ON_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).WillByDefault(Return(0));
    EXPECT_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).Times(1);

    uart_handler.receive();
}

TEST_F(Receive, ReceivePositive) {
    Uart_Handler uart_handler;

    ON_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).WillByDefault(Return(98));
    EXPECT_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).Times(1);

    uart_handler.receive();
}

TEST_F(Receive, ReceiveMaximal) {
    Uart_Handler uart_handler;

    ON_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).WillByDefault(Return(65535));
    EXPECT_CALL(*mocked_usart, usart_recv_blocking_invoke(USART2)).Times(1);

    uart_handler.receive();
}


/***** Uart_Handler::setup() *****/

class UartHandlerSetup : public ::testing::Test {
protected:
    virtual void SetUp() {
        mocked_usart = new MockUsart();
    }

    virtual void TearDown() {
        delete mocked_usart;
    }
};


TEST_F(UartHandlerSetup, Setup) {
    Uart_Handler uart_handler;

    EXPECT_CALL(*mocked_usart, usart_set_baudrate_invoke(USART2, 115200)).Times(1);
    EXPECT_CALL(*mocked_usart, usart_set_databits_invoke(USART2, 8)).Times(1);
    EXPECT_CALL(*mocked_usart, usart_set_stopbits_invoke(USART2, USART_STOPBITS_1)).Times(1);
    EXPECT_CALL(*mocked_usart, usart_set_mode_invoke(USART2, USART_MODE_TX_RX)).Times(1);
    EXPECT_CALL(*mocked_usart, usart_set_parity_invoke(USART2, USART_PARITY_NONE)).Times(1);
    EXPECT_CALL(*mocked_usart, usart_set_flow_control_invoke(USART2, USART_FLOWCONTROL_NONE)).Times(1);
    EXPECT_CALL(*mocked_usart, usart_enable_invoke(USART2)).Times(1);

    uart_handler.setup();
}
