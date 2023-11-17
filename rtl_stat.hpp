#ifndef _rtl_stat_hpp_
#define _rtl_stat_hpp_

#include <Arduino.h>

extern "C"
{
#include "stat.h"
#include "rtk_types.h"
}

class rtl_stat
{
public:
    /* Function Name:
     *      rtl_stat_global_reset
     * Description:
     *      Reset global MIB counter.
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      Reset MIB counter of ports. API will use global reset while port mask is all-ports.
     */
    rtk_api_ret_t rtl_stat_global_reset();

    /* Function Name:
     *      rtl_stat_port_reset
     * Description:
     *      Reset per port MIB counter by port.
     * Input:
     *      port - port id.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *
     */
    rtk_api_ret_t rtl_stat_port_reset(rtk_port_t port);

    /* Function Name:
     *      rtl_stat_queueManage_reset
     * Description:
     *      Reset queue manage MIB counter.
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *
     */
    rtk_api_ret_t rtl_stat_queueManage_reset();

    /* Function Name:
     *      rtl_stat_global_get
     * Description:
     *      Get global MIB counter
     * Input:
     *      cntr_idx - global counter index.
     * Output:
     *      pCntr - global counter value.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      Get global MIB counter by index definition.
     */
    rtk_api_ret_t rtl_stat_global_get(rtk_stat_global_type_t cntr_idx, rtk_stat_counter_t *pCntr);

    /* Function Name:
     *      rtl_stat_global_getAll
     * Description:
     *      Get all global MIB counter
     * Input:
     *      None
     * Output:
     *      pGlobal_cntrs - global counter structure.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      Get all global MIB counter by index definition.
     */
    rtk_api_ret_t rtl_stat_global_getAll(rtk_stat_global_cntr_t *pGlobal_cntrs);

    /* Function Name:
     *      rtl_stat_port_get
     * Description:
     *      Get per port MIB counter by index
     * Input:
     *      port        - port id.
     *      cntr_idx    - port counter index.
     * Output:
     *      pCntr - MIB retrived counter.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      Get per port MIB counter by index definition.
     */
    rtk_api_ret_t rtl_stat_port_get(rtk_port_t port, rtk_stat_port_type_t cntr_idx, rtk_stat_counter_t *pCntr);

    /* Function Name:
     *      rtl_stat_port_getAll
     * Description:
     *      Get all counters of one specified port in the specified device.
     * Input:
     *      port - port id.
     * Output:
     *      pPort_cntrs - buffer pointer of counter value.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      Get all MIB counters of one port.
     */
    rtk_api_ret_t rtl_stat_port_getAll(rtk_port_t port, rtk_stat_port_cntr_t *pPort_cntrs);

    /* Function Name:
     *      rtl_stat_logging_counterCfg_set
     * Description:
     *      Set the type and mode of Logging Counter
     * Input:
     *      idx     - The index of Logging Counter. Should be even number only.(0,2,4,6,8.....30)
     *      mode    - 32 bits or 64 bits mode
     *      type    - Packet counter or byte counter
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_OUT_OF_RANGE - Out of range.
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      Set the type and mode of Logging Counter.
     */
    rtk_api_ret_t rtl_stat_logging_counterCfg_set(rtk_uint32 idx, rtk_logging_counter_mode_t mode, rtk_logging_counter_type_t type);

    /* Function Name:
     *      rtl_stat_logging_counterCfg_get
     * Description:
     *      Get the type and mode of Logging Counter
     * Input:
     *      idx     - The index of Logging Counter. Should be even number only.(0,2,4,6,8.....30)
     * Output:
     *      pMode   - 32 bits or 64 bits mode
     *      pType   - Packet counter or byte counter
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_OUT_OF_RANGE - Out of range.
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_NULL_POINTER - NULL Pointer
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      Get the type and mode of Logging Counter.
     */
    rtk_api_ret_t rtl_stat_logging_counterCfg_get(rtk_uint32 idx, rtk_logging_counter_mode_t *pMode, rtk_logging_counter_type_t *pType);

    /* Function Name:
     *      rtl_stat_logging_counter_reset
     * Description:
     *      Reset Logging Counter
     * Input:
     *      idx     - The index of Logging Counter. (0~31)
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_OUT_OF_RANGE - Out of range.
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      Reset Logging Counter.
     */
    rtk_api_ret_t rtl_stat_logging_counter_reset(rtk_uint32 idx);

    /* Function Name:
     *      rtl_stat_logging_counter_get
     * Description:
     *      Get Logging Counter
     * Input:
     *      idx     - The index of Logging Counter. (0~31)
     * Output:
     *      pCnt    - Logging counter value
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_OUT_OF_RANGE - Out of range.
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      Get Logging Counter.
     */
    rtk_api_ret_t rtl_stat_logging_counter_get(rtk_uint32 idx, rtk_uint32 *pCnt);

    /* Function Name:
     *      rtl_stat_lengthMode_set
     * Description:
     *      Set Legnth mode.
     * Input:
     *      txMode     - The length counting mode
     *      rxMode     - The length counting mode
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_INPUT        - Out of range.
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *
     */
    rtk_api_ret_t rtl_stat_lengthMode_set(rtk_stat_lengthMode_t txMode, rtk_stat_lengthMode_t rxMode);

    /* Function Name:
     *      rtl_stat_lengthMode_get
     * Description:
     *      Get Legnth mode.
     * Input:
     *      None.
     * Output:
     *      pTxMode       - The length counting mode
     *      pRxMode       - The length counting mode
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_INPUT        - Out of range.
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     */
    rtk_api_ret_t rtl_stat_lengthMode_get(rtk_stat_lengthMode_t *pTxMode, rtk_stat_lengthMode_t *pRxMode);
};

#endif