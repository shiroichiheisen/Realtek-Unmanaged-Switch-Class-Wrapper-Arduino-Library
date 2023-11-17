#ifndef _rtl_ptp_hpp_
#define _rtl_ptp_hpp_

#include <Arduino.h>

extern "C"
{
#include "ptp.h"
#include "rtk_types.h"
}

class rtl_ptp
{
public:
    /* Function Name:
     *      rtl_ptp_init
     * Description:
     *      PTP function initialization.
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      This API is used to initialize EEE status.
     */
    rtk_api_ret_t rtl_ptp_init()
    {
        return rtk_ptp_init();
    }

    /* Function Name:
     *      rtl_ptp_mac_set
     * Description:
     *      Configure PTP mac address.
     * Input:
     *      mac - mac address to parser PTP packets.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameter.
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_mac_set(rtk_mac_t mac)
    {
        return rtk_ptp_mac_set(mac);
    }

    /* Function Name:
     *      rtl_ptp_mac_get
     * Description:
     *      Get PTP mac address.
     * Input:
     *      None
     * Output:
     *      pMac - mac address to parser PTP packets.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameter.
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_mac_get(rtk_mac_t *pMac)
    {
        return rtk_ptp_mac_get(pMac);
    }

    /* Function Name:
     *      rtl_ptp_tpid_set
     * Description:
     *      Configure PTP accepted outer & inner tag TPID.
     * Input:
     *      outerId - Ether type of S-tag frame parsing in PTP ports.
     *      innerId - Ether type of C-tag frame parsing in PTP ports.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameter.
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_tpid_set(rtk_ptp_tpid_t outerId, rtk_ptp_tpid_t innerId)
    {
        return rtk_ptp_tpid_set(outerId, innerId);
    }

    /* Function Name:
     *      rtl_ptp_tpid_get
     * Description:
     *      Get PTP accepted outer & inner tag TPID.
     * Input:
     *      None
     * Output:
     *      pOuterId - Ether type of S-tag frame parsing in PTP ports.
     *      pInnerId - Ether type of C-tag frame parsing in PTP ports.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_tpid_get(rtk_ptp_tpid_t *pOuterId, rtk_ptp_tpid_t *pInnerId)
    {
        return rtk_ptp_tpid_get(pOuterId, pInnerId);
    }

    /* Function Name:
     *      rtl_ptp_refTime_set
     * Description:
     *      Set the reference time of the specified device.
     * Input:
     *      timeStamp - reference timestamp value
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_INPUT    - invalid input parameter
     * Applicable:
     *      8390, 8380
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_refTime_set(rtk_ptp_timeStamp_t timeStamp)
    {
        return rtk_ptp_refTime_set(timeStamp);
    }

    /* Function Name:
     *      rtl_ptp_refTime_get
     * Description:
     *      Get the reference time of the specified device.
     * Input:
     * Output:
     *      pTimeStamp - pointer buffer of the reference time
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_UNIT_ID      - invalid unit id
     *      RT_ERR_NOT_INIT     - The module is not initial
     *      RT_ERR_NULL_POINTER - input parameter may be null pointer
     * Applicable:
     *      8390, 8380
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_refTime_get(rtk_ptp_timeStamp_t *pTimeStamp)
    {
        return rtk_ptp_refTime_get(pTimeStamp);
    }

    /* Function Name:
     *      rtl_ptp_refTimeAdjust_set
     * Description:
     *      Adjust the reference time.
     * Input:
     *      unit      - unit id
     *      sign      - significant
     *      timeStamp - reference timestamp value
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_UNIT_ID  - invalid unit id
     *      RT_ERR_NOT_INIT - The module is not initial
     *      RT_ERR_INPUT    - invalid input parameter
     * Note:
     *      sign=0 for positive adjustment, sign=1 for negative adjustment.
     */
    rtk_api_ret_t rtl_ptp_refTimeAdjust_set(rtk_ptp_sys_adjust_t sign, rtk_ptp_timeStamp_t timeStamp)
    {
        return rtk_ptp_refTimeAdjust_set(sign, timeStamp);
    }

    /* Function Name:
     *      rtl_ptp_refTimeEnable_set
     * Description:
     *      Set the enable state of reference time of the specified device.
     * Input:
     *      enable - status
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_INPUT    - invalid input parameter
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_refTimeEnable_set(rtk_enable_t enable)
    {
        return rtk_ptp_refTimeEnable_set(enable);
    }

    /* Function Name:
     *      rtl_ptp_refTimeEnable_get
     * Description:
     *      Get the enable state of reference time of the specified device.
     * Input:
     * Output:
     *      pEnable - status
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_UNIT_ID      - invalid unit id
     *      RT_ERR_NOT_INIT     - The module is not initial
     *      RT_ERR_NULL_POINTER - input parameter may be null pointer
     * Applicable:
     *      8390, 8380
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_refTimeEnable_get(rtk_enable_t *pEnable)
    {
        return rtk_ptp_refTimeEnable_get(pEnable);
    }

    /* Function Name:
     *      rtl_ptp_portEnable_set
     * Description:
     *      Set PTP status of the specified port.
     * Input:
     *      port   - port id
     *      enable - status
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT     - invalid port id
     *      RT_ERR_INPUT    - invalid input parameter
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_portEnable_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_ptp_portEnable_set(port, enable);
    }

    /* Function Name:
     *      rtl_ptp_portEnable_get
     * Description:
     *      Get PTP status of the specified port.
     * Input:
     *      port    - port id
     * Output:
     *      pEnable - status
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT         - invalid port id
     *      RT_ERR_NULL_POINTER - input parameter may be null pointer
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_portEnable_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_ptp_portEnable_get(port, pEnable);
    }

    /* Function Name:
     *      rtl_ptp_portTimestamp_get
     * Description:
     *      Get PTP timstamp according to the PTP identifier on the dedicated port from the specified device.
     * Input:
     *      unit       - unit id
     *      port       - port id
     *      type       - PTP message type
     * Output:
     *      pInfo      - pointer buffer of sequence ID and timestamp
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT_ID      - invalid port id
     *      RT_ERR_INPUT        - invalid input parameter
     *      RT_ERR_NULL_POINTER - input parameter may be null pointer
     * Applicable:
     *      8390, 8380
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_portTimestamp_get(rtk_port_t port, rtk_ptp_msgType_t type, rtk_ptp_info_t *pInfo)
    {
        return rtk_ptp_portTimestamp_get(port, type, pInfo);
    }

    /* Function Name:
     *      rtl_ptp_intControl_set
     * Description:
     *      Set PTP interrupt trigger status configuration.
     * Input:
     *      type - Interrupt type.
     *      enable - Interrupt status.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_ENABLE       - Invalid enable input.
     * Note:
     *      The API can set PTP interrupt status configuration.
     *      The interrupt trigger status is shown in the following:
     *          PTP_INT_TYPE_TX_SYNC = 0,
     *          PTP_INT_TYPE_TX_DELAY_REQ,
     *          PTP_INT_TYPE_TX_PDELAY_REQ,
     *          PTP_INT_TYPE_TX_PDELAY_RESP,
     *          PTP_INT_TYPE_RX_SYNC,
     *          PTP_INT_TYPE_RX_DELAY_REQ,
     *          PTP_INT_TYPE_RX_PDELAY_REQ,
     *          PTP_INT_TYPE_RX_PDELAY_RESP,
     *          PTP_INT_TYPE_ALL,
     */
    rtk_api_ret_t rtl_ptp_intControl_set(rtk_ptp_intType_t type, rtk_enable_t enable)
    {
        return rtk_ptp_intControl_set(type, enable);
    }

    /* Function Name:
     *      rtl_ptp_intControl_get
     * Description:
     *      Get PTP interrupt trigger status configuration.
     * Input:
     *      type - Interrupt type.
     * Output:
     *      pEnable - Interrupt status.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can get interrupt status configuration.
     *      The interrupt trigger status is shown in the following:
     *          PTP_INT_TYPE_TX_SYNC = 0,
     *          PTP_INT_TYPE_TX_DELAY_REQ,
     *          PTP_INT_TYPE_TX_PDELAY_REQ,
     *          PTP_INT_TYPE_TX_PDELAY_RESP,
     *          PTP_INT_TYPE_RX_SYNC,
     *          PTP_INT_TYPE_RX_DELAY_REQ,
     *          PTP_INT_TYPE_RX_PDELAY_REQ,
     *          PTP_INT_TYPE_RX_PDELAY_RESP,
     */
    rtk_api_ret_t rtl_ptp_intControl_get(rtk_ptp_intType_t type, rtk_enable_t *pEnable)
    {
        return rtk_ptp_intControl_get(type, pEnable);
    }

    /* Function Name:
     *      rtl_ptp_intStatus_get
     * Description:
     *      Get PTP port interrupt trigger status.
     * Input:
     *      port           - physical port
     * Output:
     *      pStatusMask - Interrupt status bit mask.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can get interrupt trigger status when interrupt happened.
     *      The interrupt trigger status is shown in the following:
     *      - PORT 0  INT    (value[0] (Bit0))
     *      - PORT 1  INT    (value[0] (Bit1))
     *      - PORT 2  INT    (value[0] (Bit2))
     *      - PORT 3  INT    (value[0] (Bit3))
     *      - PORT 4  INT   (value[0] (Bit4))

     *
     */
    rtk_api_ret_t rtl_ptp_intStatus_get(rtk_ptp_intStatus_t *pStatusMask)
    {
        return rtk_ptp_intStatus_get(pStatusMask);
    }

    /* Function Name:
     *      rtl_ptp_portIntStatus_set
     * Description:
     *      Set PTP port interrupt trigger status to clean.
     * Input:
     *      port           - physical port
     *      statusMask - Interrupt status bit mask.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT - Invalid input parameters.
     * Note:
     *      The API can clean interrupt trigger status when interrupt happened.
     *      The interrupt trigger status is shown in the following:
     *      - PTP_INT_TYPE_TX_SYNC              (value[0] (Bit0))
     *      - PTP_INT_TYPE_TX_DELAY_REQ      (value[0] (Bit1))
     *      - PTP_INT_TYPE_TX_PDELAY_REQ    (value[0] (Bit2))
     *      - PTP_INT_TYPE_TX_PDELAY_RESP   (value[0] (Bit3))
     *      - PTP_INT_TYPE_RX_SYNC              (value[0] (Bit4))
     *      - PTP_INT_TYPE_RX_DELAY_REQ      (value[0] (Bit5))
     *      - PTP_INT_TYPE_RX_PDELAY_REQ    (value[0] (Bit6))
     *      - PTP_INT_TYPE_RX_PDELAY_RESP   (value[0] (Bit7))
     *      The status will be cleared after execute this API.
     */
    rtk_api_ret_t rtl_ptp_portIntStatus_set(rtk_port_t port, rtk_ptp_intStatus_t statusMask)
    {
        return rtk_ptp_portIntStatus_set(port, statusMask);
    }

    /* Function Name:
     *      rtl_ptp_portIntStatus_get
     * Description:
     *      Get PTP port interrupt trigger status.
     * Input:
     *      port           - physical port
     * Output:
     *      pStatusMask - Interrupt status bit mask.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can get interrupt trigger status when interrupt happened.
     *      The interrupt trigger status is shown in the following:
     *      - PTP_INT_TYPE_TX_SYNC              (value[0] (Bit0))
     *      - PTP_INT_TYPE_TX_DELAY_REQ      (value[0] (Bit1))
     *      - PTP_INT_TYPE_TX_PDELAY_REQ    (value[0] (Bit2))
     *      - PTP_INT_TYPE_TX_PDELAY_RESP   (value[0] (Bit3))
     *      - PTP_INT_TYPE_RX_SYNC              (value[0] (Bit4))
     *      - PTP_INT_TYPE_RX_DELAY_REQ      (value[0] (Bit5))
     *      - PTP_INT_TYPE_RX_PDELAY_REQ    (value[0] (Bit6))
     *      - PTP_INT_TYPE_RX_PDELAY_RESP   (value[0] (Bit7))
     *
     */
    rtk_api_ret_t rtl_ptp_portIntStatus_get(rtk_port_t port, rtk_ptp_intStatus_t *pStatusMask)
    {
        return rtk_ptp_portIntStatus_get(port, pStatusMask);
    }

    /* Function Name:
     *      rtl_ptp_portTrap_set
     * Description:
     *      Set PTP packet trap of the specified port.
     * Input:
     *      port   - port id
     *      enable - status
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT     - invalid port id
     *      RT_ERR_INPUT    - invalid input parameter
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_portTrap_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_ptp_portTrap_set(port, enable);
    }

    /* Function Name:
     *      rtl_ptp_portTrap_get
     * Description:
     *      Get PTP packet trap of the specified port.
     * Input:
     *      port    - port id
     * Output:
     *      pEnable - status
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT         - invalid port id
     *      RT_ERR_NULL_POINTER - input parameter may be null pointer
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_ptp_portTrap_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_ptp_portTrap_get(port, pEnable);
    }
};

#endif