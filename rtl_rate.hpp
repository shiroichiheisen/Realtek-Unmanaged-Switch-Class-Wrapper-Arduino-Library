#ifndef _rtl_rate_hpp_
#define _rtl_rate_hpp_

#include <Arduino.h>

extern "C"
{
#include "rate.h"
#include "rtk_types.h"
}

class rtl_rate
{
public:
    /* Function Name:
     *      rtl_rate_shareMeter_set
     * Description:
     *      Set meter configuration
     * Input:
     *      index       - shared meter index
     *      type        - shared meter type
     *      rate        - rate of share meter
     *      ifg_include - include IFG or not, ENABLE:include DISABLE:exclude
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_FILTER_METER_ID  - Invalid meter
     *      RT_ERR_RATE             - Invalid rate
     *      RT_ERR_INPUT            - Invalid input parameters
     * Note:
     *      The API can set shared meter rate and ifg include for each meter.
     *      The rate unit is 1 kbps and the range is from 8k to 1048568k if type is METER_TYPE_KBPS and
     *      the granularity of rate is 8 kbps.
     *      The rate unit is packets per second and the range is 1 ~ 0x1FFF if type is METER_TYPE_PPS.
     *      The ifg_include parameter is used
     *      for rate calculation with/without inter-frame-gap and preamble.
     */
    rtk_api_ret_t rtl_rate_shareMeter_set(rtk_meter_id_t index, rtk_meter_type_t type, rtk_rate_t rate, rtk_enable_t ifg_include)
    {
        return rtk_rate_shareMeter_set(index, type, rate, ifg_include);
    }

    /* Function Name:
     *      rtl_rate_shareMeter_get
     * Description:
     *      Get meter configuration
     * Input:
     *      index        - shared meter index
     * Output:
     *      pType        - Meter Type
     *      pRate        - pointer of rate of share meter
     *      pIfg_include - include IFG or not, ENABLE:include DISABLE:exclude
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_FILTER_METER_ID  - Invalid meter
     * Note:
     *
     */
    rtk_api_ret_t rtl_rate_shareMeter_get(rtk_meter_id_t index, rtk_meter_type_t *pType, rtk_rate_t *pRate, rtk_enable_t *pIfg_include)
    {
        return rtk_rate_shareMeter_get(index, pType, pRate, pIfg_include);
    }

    /* Function Name:
     *      rtl_rate_shareMeterBucket_set
     * Description:
     *      Set meter Bucket Size
     * Input:
     *      index        - shared meter index
     *      bucket_size  - Bucket Size
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_INPUT            - Error Input
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_FILTER_METER_ID  - Invalid meter
     * Note:
     *      The API can set shared meter bucket size.
     */
    rtk_api_ret_t rtl_rate_shareMeterBucket_set(rtk_meter_id_t index, rtk_uint32 bucket_size)
    {
        return rtk_rate_shareMeterBucket_set(index, bucket_size);
    }

    /* Function Name:
     *      rtl_rate_shareMeterBucket_get
     * Description:
     *      Get meter Bucket Size
     * Input:
     *      index        - shared meter index
     * Output:
     *      pBucket_size - Bucket Size
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_FILTER_METER_ID  - Invalid meter
     * Note:
     *      The API can get shared meter bucket size.
     */
    rtk_api_ret_t rtl_rate_shareMeterBucket_get(rtk_meter_id_t index, rtk_uint32 *pBucket_size)
    {
        return rtk_rate_shareMeterBucket_get(index, pBucket_size);
    }

    /* Function Name:
     *      rtl_rate_igrBandwidthCtrlRate_set
     * Description:
     *      Set port ingress bandwidth control
     * Input:
     *      port        - Port id
     *      rate        - Rate of share meter
     *      ifg_include - include IFG or not, ENABLE:include DISABLE:exclude
     *      fc_enable   - enable flow control or not, ENABLE:use flow control DISABLE:drop
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_ENABLE       - Invalid IFG parameter.
     *      RT_ERR_INBW_RATE    - Invalid ingress rate parameter.
     * Note:
     *      The rate unit is 1 kbps and the range is from 8k to 1048568k. The granularity of rate is 8 kbps.
     *      The ifg_include parameter is used for rate calculation with/without inter-frame-gap and preamble.
     */
    rtk_api_ret_t rtl_rate_igrBandwidthCtrlRate_set(rtk_port_t port, rtk_rate_t rate, rtk_enable_t ifg_include, rtk_enable_t fc_enable)
    {
        return rtk_rate_igrBandwidthCtrlRate_set(port, rate, ifg_include, fc_enable);
    }

    /* Function Name:
     *      rtl_rate_igrBandwidthCtrlRate_get
     * Description:
     *      Get port ingress bandwidth control
     * Input:
     *      port - Port id
     * Output:
     *      pRate           - Rate of share meter
     *      pIfg_include    - Rate's calculation including IFG, ENABLE:include DISABLE:exclude
     *      pFc_enable      - enable flow control or not, ENABLE:use flow control DISABLE:drop
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *     The rate unit is 1 kbps and the range is from 8k to 1048568k. The granularity of rate is 8 kbps.
     *     The ifg_include parameter is used for rate calculation with/without inter-frame-gap and preamble.
     */
    rtk_api_ret_t rtl_rate_igrBandwidthCtrlRate_get(rtk_port_t port, rtk_rate_t *pRate, rtk_enable_t *pIfg_include, rtk_enable_t *pFc_enable)
    {
        return rtk_rate_igrBandwidthCtrlRate_get(port, pRate, pIfg_include, pFc_enable);
    }

    /* Function Name:
     *      rtl_rate_egrBandwidthCtrlRate_set
     * Description:
     *      Set port egress bandwidth control
     * Input:
     *      port        - Port id
     *      rate        - Rate of egress bandwidth
     *      ifg_include - include IFG or not, ENABLE:include DISABLE:exclude
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_QOS_EBW_RATE - Invalid egress bandwidth/rate
     * Note:
     *     The rate unit is 1 kbps and the range is from 8k to 1048568k. The granularity of rate is 8 kbps.
     *     The ifg_include parameter is used for rate calculation with/without inter-frame-gap and preamble.
     */
    rtk_api_ret_t rtl_rate_egrBandwidthCtrlRate_set(rtk_port_t port, rtk_rate_t rate, rtk_enable_t ifg_includ)
    {
        return rtk_rate_egrBandwidthCtrlRate_set(port, rate, ifg_includ);
    }

    /* Function Name:
     *      rtl_rate_egrBandwidthCtrlRate_get
     * Description:
     *      Get port egress bandwidth control
     * Input:
     *      port - Port id
     * Output:
     *      pRate           - Rate of egress bandwidth
     *      pIfg_include    - Rate's calculation including IFG, ENABLE:include DISABLE:exclude
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *     The rate unit is 1 kbps and the range is from 8k to 1048568k. The granularity of rate is 8 kbps.
     *     The ifg_include parameter is used for rate calculation with/without inter-frame-gap and preamble.
     */
    rtk_api_ret_t rtl_rate_egrBandwidthCtrlRate_get(rtk_port_t port, rtk_rate_t *pRate, rtk_enable_t *pIfg_include)
    {
        return rtk_rate_egrBandwidthCtrlRate_get(port, pRate, pIfg_include);
    }

    /* Function Name:
     *      rtl_rate_egrQueueBwCtrlEnable_set
     * Description:
     *      Set enable status of egress bandwidth control on specified queue.
     * Input:
     *      port   - port id
     *      queue  - queue id
     *      enable - enable status of egress queue bandwidth control
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT_ID          - invalid port id
     *      RT_ERR_QUEUE_ID         - invalid queue id
     *      RT_ERR_INPUT            - invalid input parameter
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_rate_egrQueueBwCtrlEnable_set(rtk_port_t port, rtk_qid_t queue, rtk_enable_t enable)
    {
        return rtk_rate_egrQueueBwCtrlEnable_set(port, queue, enable);
    }

    /* Function Name:
     *      rtl_rate_egrQueueBwCtrlEnable_get
     * Description:
     *      Get rate of egress bandwidth control on specified queue.
     * Input:
     *      port  - port id
     *      queue - queue id
     *      pIndex - shared meter index
     * Output:
     *      pRate - pointer to rate of egress queue bandwidth control
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT_ID          - invalid port id
     *      RT_ERR_QUEUE_ID         - invalid queue id
     *      RT_ERR_FILTER_METER_ID  - Invalid meter id
     * Note:
     *    None.
     */
    rtk_api_ret_t rtl_rate_egrQueueBwCtrlEnable_get(rtk_port_t port, rtk_qid_t queue, rtk_enable_t *pEnable)
    {
        return rtk_rate_egrQueueBwCtrlEnable_get(port, queue, pEnable);
    }

    /* Function Name:
     *      rtl_rate_egrQueueBwCtrlRate_set
     * Description:
     *      Set rate of egress bandwidth control on specified queue.
     * Input:
     *      port  - port id
     *      queue - queue id
     *      index - shared meter index
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT_ID          - invalid port id
     *      RT_ERR_QUEUE_ID         - invalid queue id
     *      RT_ERR_FILTER_METER_ID  - Invalid meter id
     * Note:
     *    The actual rate control is set in shared meters.
     *    The unit of granularity is 8Kbps.
     */
    rtk_api_ret_t rtl_rate_egrQueueBwCtrlRate_set(rtk_port_t port, rtk_qid_t queue, rtk_meter_id_t index)
    {
        return rtk_rate_egrQueueBwCtrlRate_set(port, queue, index);
    }

    /* Function Name:
     *      rtl_rate_egrQueueBwCtrlRate_get
     * Description:
     *      Get rate of egress bandwidth control on specified queue.
     * Input:
     *      port  - port id
     *      queue - queue id
     *      pIndex - shared meter index
     * Output:
     *      pRate - pointer to rate of egress queue bandwidth control
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT_ID          - invalid port id
     *      RT_ERR_QUEUE_ID         - invalid queue id
     *      RT_ERR_FILTER_METER_ID  - Invalid meter id
     * Note:
     *    The actual rate control is set in shared meters.
     *    The unit of granularity is 8Kbps.
     */
    rtk_api_ret_t rtl_rate_egrQueueBwCtrlRate_get(rtk_port_t port, rtk_qid_t queue, rtk_meter_id_t *pIndex)
    {
        return rtk_rate_egrQueueBwCtrlRate_get(port, queue, pIndex);
    }
};

#endif