/**
 * @file HwAbstractionLayerUartInterface.h
 *
 * @brief This file defines the Hardware Abstraction Layer interface for UART
 *
 * @Author Aniket Sedhai
 * @date 09/24/2024
 */

#ifndef HARDWARE_ABSTRACTION_LAYER_UART_INTERFACE_H
#define HARDWARE_ABSTRACTION_LAYER_UART_INTERFACE_H
 

/* ====================================================================================================================
 * INCLUDES
 * ====================================================================================================================
 */

#include <cstdint>

/* ====================================================================================================================
 * PUBLIC DEFINES
 * ====================================================================================================================
 */

/*UART Baud Rates*/
#define HW_ABSTRACTION_LAYER_INTERFACE_UART_BAUD_RATE_9600          (9600U)
#define HW_ABSTRACTION_LAYER_INTERFACE_UART_BAUD_RATE_19200         (19200U)
#define HW_ABSTRACTION_LAYER_INTERFACE_UART_BAUD_RATE_28800         (28800U)
#define HW_ABSTRACTION_LAYER_INTERFACE_UART_BAUD_RATE_38400         (38400U)
#define HW_ABSTRACTION_LAYER_INTERFACE_UART_BAUD_RATE_57600         (57600U)
#define HW_ABSTRACTION_LAYER_INTERFACE_UART_BAUD_RATE_76800         (76800U)
#define HW_ABSTRACTION_LAYER_INTERFACE_UART_BAUD_RATE_115200        (115200U)
#define HW_ABSTRACTION_LAYER_INTERFACE_UART_BAUD_RATE_230400        (230400U)
#define HW_ABSTRACTION_LAYER_INTERFACE_UART_BAUD_RATE_460800        (460800U)
#define HW_ABSTRACTION_LAYER_INTERFACE_UART_BAUD_RATE_576000        (576000U)
#define HW_ABSTRACTION_LAYER_INTERFACE_UART_BAUD_RATE_921600        (921600U)

namespace HwAbstractionLayerUartInterfaceNamespace
{
    /* ================================================================================================================
     * PUBLIC ENUMERATIONS
     * ================================================================================================================
     */

    enum class hal_uart_status_e
    {
        HAL_UART_STATUS_SUCCESS = 0,                            /*!<success*/
        HAL_UART_STATUS_NULL_POINTER_ERROR,                     /*!<null pointer error*/
        HAL_UART_STATUS_INIT_ERROR,                             /*!<init error*/
        HAL_UART_STATUS_ENABLE_ERROR,                           /*!<enable error*/
        HAL_UART_STATUS_DISABLE_ERROR,                          /*!<disable error*/
        HAL_UART_STATUS_BLOCKING_WRITE_ERROR,                   /*!<blocking write error*/
        HAL_UART_STATUS_PRESENT_READ_BYTE_TO_APPLICATION_ERROR, /*!<present read byte to application error*/
        HAL_UART_STATUS_INTERFACE_DOES_NOT_EXIST_ERROR,         /*!<interface does not exist error*/
        HAL_UART_STATUS_INTERFACE_NOT_INITIALIZED_ERROR,        /*!<interface is not initialized error*/
        HAL_UART_STATUS_BAUD_RATE_NOT_SUPPORTED_ERROR,          /*!<baud rate not supported error*/
        HAL_UART_STATUS_TIMEOUT_ERROR,                          /*!<timeout error*/
        HAL_UART_STATUS_FUNCTIONALITY_NOT_SUPPORTED_ERROR,      /*!<funtionality not supported error*/
    };
    
}

/* ====================================================================================================================
 * CLASS DECLARATION
 * ====================================================================================================================
 */

class HwAbstractionLayerUartInterface
{
    public:
    
    /**
     * @brief This method initializes UART interface.
     * 
     * @param[in] baud_rate - Baud rate to initialize the UART
     * @param[out] ret_platform_specific_status_p - pointer to set platform specific status, can be NULL
     * @return HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e - returns zero upon success, non-zero upon
     * failure
     */
    virtual HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_init(
      uint32_t baud_rate,
      int32_t* ret_platform_specific_status_p) = 0;

    /**
     * @brief This method returns the initialization state of the uart interface.
     * 
     * @return true - is initialized
     * @return false - is not initialized
     */
    virtual bool hal_uart_is_initialized(void) = 0;

    /**
     * @brief This method returns if the UART interface is enable to receive data.
     * 
     * @return true - is enabled
     * @return false - is not enabled
     */
    virtual bool hal_uart_is_rx_enabled(void) = 0;

        virtual HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_enable_rx(
            int32_t* ret_platform_specific_status_p) = 0;

        /**
         * @brief Function is for enabling the Tx UART interface.
         * 
         * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
         * @return hal_uart_status_e                  - returns zero upon success, non-zero upon failure
         */
        virtual HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_enable_tx(
            int32_t* ret_platform_specific_status_p) = 0;

        /**
         * @brief Function is for disabling both Rx and Tx UART interface.
         * 
         * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
         * @return hal_uart_status_e                  - returns zero upon success, non-zero upon failure
         */
        virtual HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_disable_both_rx_tx(
            int32_t* ret_platform_specific_status_p) = 0;

        /**
         * @brief Function is for disabling the Rx UART interface.
         * 
         * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
         * @return hal_uart_status_e                  - returns zero upon success, non-zero upon failure
         */
        virtual HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_disable_rx(
            int32_t* ret_platform_specific_status_p) = 0;

        /**
         * @brief Function is for disabling the Tx UART interface.
         * 
         * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
         * @return hal_uart_status_e                  - returns zero upon success, non-zero upon failure
         */
        virtual HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_disable_tx(
            int32_t* ret_platform_specific_status_p) = 0;

        /**
         * @brief Function for a blocking write to an UART interface.
         * 
         * @param[in] wrt_bytes_p                     - pointer in data to write
         * @param[in] num_of_bytes                    - number of bytes wrt_bytes_p is pointing to
         * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
         * @return hal_uart_status_e                  - returns zero upon success, non-zero upon failure
         */
        virtual HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_write(
            const uint8_t* wrt_bytes_p,
            uint32_t       num_of_bytes,
            int32_t*       ret_platform_specific_status_p) = 0;

        /**
         * @brief This function presents a byte to the application from the UART interface.
         * 
         * @param[in] rd_byte                         - byte received from the serial port
         * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
         * @return hal_uart_status_e                  - returns zero upon success, non-zero upon failure
         * @note This function is usually call with the context of an ISR.
         */
        virtual HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_present_read_byte_to_applicaition(
            uint8_t  rd_byte,
            int32_t* ret_platform_specific_status_p) = 0;

        // /**
        //  * @brief This function sets the callback that is used to send the application the received uart byte.
        //  * 
        //  * @param[in] callback_fp      - pointer the callback function.
        //  * @param[in] arg_p            - pointer the argument passed back.
        //  * @return hal_uart_status_e   - returns zero upon success, non-zero upon failure.
        //  */
        // virtual HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_set_application_rx_callback(
        //     HwAbstractionLayerUartInterfaceNamespace::application_rx_byte_callback_func_t callback_fp,
        //     void* arg_p) = 0;

        /**
         * @brief Destructor. 
         */
        virtual ~HwAbstractionLayerUartInterface(){}
        
    protected:
        
        /**
         * @brief Default constructor made protected since this is an abstract class. 
         */
        HwAbstractionLayerUartInterface(){}
        
    private:

};

#endif /*HARDWARE_ABSTRACTION_LAYER_UART_INTERFACE_H*/
