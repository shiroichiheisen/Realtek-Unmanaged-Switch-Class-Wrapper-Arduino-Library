#ifndef _rtl_qos_hpp_
#define _rtl_qos_hpp_

#include <Arduino.h>

extern "C"
{
#include "qos.h"
#include "rtk_types.h"
}

class rtl_qos
{
public:
    /* Function Name:
     *      rtl_qos_init
     * Description:
     *      Configure Qos default settings with queue number assigment to each port.
     * Input:
     *      queueNum - Queue number of each port.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_QUEUE_NUM    - Invalid queue number.
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This API will initialize related Qos setting with queue number assigment.
     *      The queue number is from 1 to 8.
     */
    rtk_api_ret_t rtl_qos_init(rtk_queue_num_t queueNum)
    {
        return rtk_qos_init(queueNum);
    }

    /* Function Name:
     *      rtl_qos_priSel_set
     * Description:
     *      Configure the priority order among different priority mechanism.
     * Input:
     *      index - Priority decision table index (0~1)
     *      pPriDec - Priority assign for port, dscp, 802.1p, cvlan, svlan, acl based priority decision.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_QOS_SEL_PRI_SOURCE   - Invalid priority decision source parameter.
     * Note:
     *      ASIC will follow user priority setting of mechanisms to select mapped queue priority for receiving frame.
     *      If two priority mechanisms are the same, the ASIC will chose the highest priority from mechanisms to
     *      assign queue priority to receiving frame.
     *      The priority sources are:
     *      - PRIDEC_PORT
     *      - PRIDEC_ACL
     *      - PRIDEC_DSCP
     *      - PRIDEC_1Q
     *      - PRIDEC_1AD
     *      - PRIDEC_CVLAN
     *      - PRIDEC_DA
     *      - PRIDEC_SA
     */
    rtk_api_ret_t rtl_qos_priSel_set(rtk_qos_priDecTbl_t index, rtk_priority_select_t *pPriDec)
    {
        return rtk_qos_priSel_set(index, pPriDec);
    }

    /* Function Name:
     *      rtl_qos_priSel_get
     * Description:
     *      Get the priority order configuration among different priority mechanism.
     * Input:
     *      index - Priority decision table index (0~1)
     * Output:
     *      pPriDec - Priority assign for port, dscp, 802.1p, cvlan, svlan, acl based priority decision .
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      ASIC will follow user priority setting of mechanisms to select mapped queue priority for receiving frame.
     *      If two priority mechanisms are the same, the ASIC will chose the highest priority from mechanisms to
     *      assign queue priority to receiving frame.
     *      The priority sources are:
     *      - PRIDEC_PORT,
     *      - PRIDEC_ACL,
     *      - PRIDEC_DSCP,
     *      - PRIDEC_1Q,
     *      - PRIDEC_1AD,
     *      - PRIDEC_CVLAN,
     *      - PRIDEC_DA,
     *      - PRIDEC_SA,
     */
    rtk_api_ret_t rtl_qos_priSel_get(rtk_qos_priDecTbl_t index, rtk_priority_select_t *pPriDec)
    {
        return rtk_qos_priSel_get(index, pPriDec);
    }

    /* Function Name:
     *      rtl_qos_1pPriRemap_set
     * Description:
     *      Configure 1Q priorities mapping to internal absolute priority.
     * Input:
     *      dot1p_pri   - 802.1p priority value.
     *      int_pri     - internal priority value.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_INPUT            - Invalid input parameters.
     *      RT_ERR_VLAN_PRIORITY    - Invalid 1p priority.
     *      RT_ERR_QOS_INT_PRIORITY - Invalid priority.
     * Note:
     *      Priority of 802.1Q assignment for internal asic priority, and it is used for queue usage and packet scheduling.
     */
    rtk_api_ret_t rtl_qos_1pPriRemap_set(rtk_pri_t dot1p_pri, rtk_pri_t int_pri)
    {
        return rtk_qos_1pPriRemap_set(dot1p_pri, int_pri);
    }

    /* Function Name:
     *      rtl_qos_1pPriRemap_get
     * Description:
     *      Get 1Q priorities mapping to internal absolute priority.
     * Input:
     *      dot1p_pri - 802.1p priority value .
     * Output:
     *      pInt_pri - internal priority value.
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_VLAN_PRIORITY    - Invalid priority.
     *      RT_ERR_QOS_INT_PRIORITY - Invalid priority.
     * Note:
     *      Priority of 802.1Q assigment for internal asic priority, and it is uesed for queue usage and packet scheduling.
     */
    rtk_api_ret_t rtl_qos_1pPriRemap_get(rtk_pri_t dot1p_pri, rtk_pri_t *pInt_pri)
    {
        return rtk_qos_1pPriRemap_get(dot1p_pri, pInt_pri);
    }

    /* Function Name:
     *      rtl_qos_1pRemarkSrcSel_set
     * Description:
     *      Set remarking source of 802.1p remarking.
     * Input:
     *      type      - remarking source
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_NOT_INIT         - The module is not initial
     *      RT_ERR_PORT_ID  - invalid port id
     *      RT_ERR_INPUT            - invalid input parameter

     * Note:
     *      The API can configure 802.1p remark functionality to map original 802.1p value or internal
     *      priority to TX DSCP value.
     */
    rtk_api_ret_t rtl_qos_1pRemarkSrcSel_set(rtk_qos_1pRmkSrc_t type)
    {
        return rtk_qos_1pRemarkSrcSel_set(type);
    }

    /* Function Name:
     *      rtl_qos_1pRemarkSrcSel_get
     * Description:
     *      Get remarking source of 802.1p remarking.
     * Input:
     *      none
     * Output:
     *      pType      - remarking source
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_NOT_INIT         - The module is not initial
     *      RT_ERR_PORT_ID          - invalid port id
     *      RT_ERR_INPUT            - invalid input parameter
     *      RT_ERR_NULL_POINTER     - input parameter may be null pointer

     * Note:
     *      None
     */
    rtk_api_ret_t rtl_qos_1pRemarkSrcSel_get(rtk_qos_1pRmkSrc_t *pType)
    {
        return rtk_qos_1pRemarkSrcSel_get(pType);
    }

    /* Function Name:
     *      rtl_qos_dscpPriRemap_set
     * Description:
     *      Map dscp value to internal priority.
     * Input:
     *      dscp    - Dscp value of receiving frame
     *      int_pri - internal priority value .
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_INPUT            - Invalid input parameters.
     *      RT_ERR_QOS_DSCP_VALUE   - Invalid DSCP value.
     *      RT_ERR_QOS_INT_PRIORITY - Invalid priority.
     * Note:
     *      The Differentiated Service Code Point is a selector for router's per-hop behaviors. As a selector, there is no implication that a numerically
     *      greater DSCP implies a better network service. As can be seen, the DSCP totally overlaps the old precedence field of TOS. So if values of
     *      DSCP are carefully chosen then backward compatibility can be achieved.
     */
    rtk_api_ret_t rtl_qos_dscpPriRemap_set(rtk_dscp_t dscp, rtk_pri_t int_pri)
    {
        return rtk_qos_dscpPriRemap_set(dscp, int_pri);
    }

    /* Function Name:
     *      rtl_qos_dscpPriRemap_get
     * Description:
     *      Get dscp value to internal priority.
     * Input:
     *      dscp - Dscp value of receiving frame
     * Output:
     *      pInt_pri - internal priority value.
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_QOS_DSCP_VALUE   - Invalid DSCP value.
     * Note:
     *      The Differentiated Service Code Point is a selector for router's per-hop behaviors. As a selector, there is no implication that a numerically
     *      greater DSCP implies a better network service. As can be seen, the DSCP totally overlaps the old precedence field of TOS. So if values of
     *      DSCP are carefully chosen then backward compatibility can be achieved.
     */
    rtk_api_ret_t rtl_qos_dscpPriRemap_get(rtk_dscp_t dscp, rtk_pri_t *pInt_pri)
    {
        return rtk_qos_dscpPriRemap_get(dscp, pInt_pri);
    }

    /* Function Name:
     *      rtl_qos_portPri_set
     * Description:
     *      Configure priority usage to each port.
     * Input:
     *      port - Port id.
     *      int_pri - internal priority value.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_QOS_SEL_PORT_PRI - Invalid port priority.
     *      RT_ERR_QOS_INT_PRIORITY - Invalid priority.
     * Note:
     *      The API can set priority of port assignments for queue usage and packet scheduling.
     */
    rtk_api_ret_t rtl_qos_portPri_set(rtk_port_t port, rtk_pri_t int_pri)
    {
        return rtk_qos_portPri_set(port, int_pri);
    }

    /* Function Name:
     *      rtl_qos_portPri_get
     * Description:
     *      Get priority usage to each port.
     * Input:
     *      port - Port id.
     * Output:
     *      pInt_pri - internal priority value.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can get priority of port assignments for queue usage and packet scheduling.
     */
    rtk_api_ret_t rtl_qos_portPri_get(rtk_port_t port, rtk_pri_t *pInt_pri)
    {
        return rtk_qos_portPri_get(port, pInt_pri);
    }

    /* Function Name:
     *      rtl_qos_queueNum_set
     * Description:
     *      Set output queue number for each port.
     * Input:
     *      port    - Port id.
     *      index   - Mapping queue number (1~8)
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_QUEUE_NUM    - Invalid queue number.
     * Note:
     *      The API can set the output queue number of the specified port. The queue number is from 1 to 8.
     */
    rtk_api_ret_t rtl_qos_queueNum_set(rtk_port_t port, rtk_queue_num_t queue_num)
    {
        return rtk_qos_queueNum_set(port, queue_num);
    }

    /* Function Name:
     *      rtl_qos_queueNum_get
     * Description:
     *      Get output queue number.
     * Input:
     *      port - Port id.
     * Output:
     *      pQueue_num - Mapping queue number
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API will return the output queue number of the specified port. The queue number is from 1 to 8.
     */
    rtk_api_ret_t rtl_qos_queueNum_get(rtk_port_t port, rtk_queue_num_t *pQueue_num)
    {
        return rtk_qos_queueNum_get(port, pQueue_num);
    }

    /* Function Name:
     *      rtl_qos_priMap_set
     * Description:
     *      Set output queue number for each port.
     * Input:
     *      queue_num   - Queue number usage.
     *      pPri2qid    - Priority mapping to queue ID.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_INPUT            - Invalid input parameters.
     *      RT_ERR_QUEUE_NUM        - Invalid queue number.
     *      RT_ERR_QUEUE_ID         - Invalid queue id.
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_QOS_INT_PRIORITY - Invalid priority.
     * Note:
     *      ASIC supports priority mapping to queue with different queue number from 1 to 8.
     *      For different queue numbers usage, ASIC supports different internal available queue IDs.
     */
    rtk_api_ret_t rtl_qos_priMap_set(rtk_queue_num_t queue_num, rtk_qos_pri2queue_t *pPri2qid)
    {
        return rtk_qos_priMap_set(queue_num, pPri2qid);
    }

    /* Function Name:
     *      rtl_qos_priMap_get
     * Description:
     *      Get priority to queue ID mapping table parameters.
     * Input:
     *      queue_num - Queue number usage.
     * Output:
     *      pPri2qid - Priority mapping to queue ID.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_QUEUE_NUM    - Invalid queue number.
     * Note:
     *      The API can return the mapping queue id of the specified priority and queue number.
     *      The queue number is from 1 to 8.
     */
    rtk_api_ret_t rtl_qos_priMap_get(rtk_queue_num_t queue_num, rtk_qos_pri2queue_t *pPri2qid)
    {
        return rtk_qos_priMap_get(queue_num, pPri2qid);
    }

    /* Function Name:
     *      rtl_qos_schedulingQueue_set
     * Description:
     *      Set weight and type of queues in dedicated port.
     * Input:
     *      port        - Port id.
     *      pQweights   - The array of weights for WRR/WFQ queue (0 for STRICT_PRIORITY queue).
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_QOS_QUEUE_WEIGHT - Invalid queue weight.
     * Note:
     *      The API can set weight and type, strict priority or weight fair queue (WFQ) for
     *      dedicated port for using queues. If queue id is not included in queue usage,
     *      then its type and weight setting in dummy for setting. There are priorities
     *      as queue id in strict queues. It means strict queue id 5 carrying higher priority
     *      than strict queue id 4. The WFQ queue weight is from 1 to 128, and weight 0 is
     *      for strict priority queue type.
     */
    rtk_api_ret_t rtl_qos_schedulingQueue_set(rtk_port_t port, rtk_qos_queue_weights_t *pQweights)
    {
        return rtk_qos_schedulingQueue_set(port, pQweights);
    }

    /* Function Name:
     *      rtl_qos_schedulingQueue_get
     * Description:
     *      Get weight and type of queues in dedicated port.
     * Input:
     *      port - Port id.
     * Output:
     *      pQweights - The array of weights for WRR/WFQ queue (0 for STRICT_PRIORITY queue).
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get weight and type, strict priority or weight fair queue (WFQ) for dedicated port for using queues.
     *      The WFQ queue weight is from 1 to 128, and weight 0 is for strict priority queue type.
     */
    rtk_api_ret_t rtl_qos_schedulingQueue_get(rtk_port_t port, rtk_qos_queue_weights_t *pQweights)
    {
        return rtk_qos_schedulingQueue_get(port, pQweights);
    }

    /* Function Name:
     *      rtl_qos_1pRemarkEnable_set
     * Description:
     *      Set 1p Remarking state
     * Input:
     *      port        - Port id.
     *      enable      - State of per-port 1p Remarking
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_ENABLE       - Invalid enable parameter.
     * Note:
     *      The API can enable or disable 802.1p remarking ability for whole system.
     *      The status of 802.1p remark:
     *      - DISABLED
     *      - ENABLED
     */
    rtk_api_ret_t rtl_qos_1pRemarkEnable_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_qos_1pRemarkEnable_set(port, enable);
    }

    /* Function Name:
     *      rtl_qos_1pRemarkEnable_get
     * Description:
     *      Get 802.1p remarking ability.
     * Input:
     *      port - Port id.
     * Output:
     *      pEnable - Status of 802.1p remark.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get 802.1p remarking ability.
     *      The status of 802.1p remark:
     *      - DISABLED
     *      - ENABLED
     */
    rtk_api_ret_t rtl_qos_1pRemarkEnable_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_qos_1pRemarkEnable_get(port, pEnable);
    }

    /* Function Name:
     *      rtl_qos_1pRemark_set
     * Description:
     *      Set 802.1p remarking parameter.
     * Input:
     *      int_pri     - Internal priority value.
     *      dot1p_pri   - 802.1p priority value.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_VLAN_PRIORITY    - Invalid 1p priority.
     *      RT_ERR_QOS_INT_PRIORITY - Invalid priority.
     * Note:
     *      The API can set 802.1p parameters source priority and new priority.
     */
    rtk_api_ret_t rtl_qos_1pRemark_set(rtk_pri_t int_pri, rtk_pri_t dot1p_pri)
    {
        return rtk_qos_1pRemark_set(int_pri, dot1p_pri);
    }

    /* Function Name:
     *      rtl_qos_1pRemark_get
     * Description:
     *      Get 802.1p remarking parameter.
     * Input:
     *      int_pri - Internal priority value.
     * Output:
     *      pDot1p_pri - 802.1p priority value.
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_QOS_INT_PRIORITY - Invalid priority.
     * Note:
     *      The API can get 802.1p remarking parameters. It would return new priority of ingress priority.
     */
    rtk_api_ret_t rtl_qos_1pRemark_get(rtk_pri_t int_pri, rtk_pri_t *pDot1p_pri)
    {
        return rtk_qos_1pRemark_get(int_pri, pDot1p_pri);
    }

    /* Function Name:
     *      rtl_qos_dscpRemarkEnable_set
     * Description:
     *      Set DSCP remarking ability.
     * Input:
     *      port    - Port id.
     *      enable  - status of DSCP remark.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_QOS_INT_PRIORITY - Invalid priority.
     *      RT_ERR_ENABLE           - Invalid enable parameter.
     * Note:
     *      The API can enable or disable DSCP remarking ability for whole system.
     *      The status of DSCP remark:
     *      - DISABLED
     *      - ENABLED
     */
    rtk_api_ret_t rtl_qos_dscpRemarkEnable_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_qos_dscpRemarkEnable_set(port, enable);
    }

    /* Function Name:
     *      rtl_qos_dscpRemarkEnable_get
     * Description:
     *      Get DSCP remarking ability.
     * Input:
     *      port - Port id.
     * Output:
     *      pEnable - status of DSCP remarking.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get DSCP remarking ability.
     *      The status of DSCP remark:
     *      - DISABLED
     *      - ENABLED
     */
    rtk_api_ret_t rtl_qos_dscpRemarkEnable_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_qos_dscpRemarkEnable_get(port, pEnable);
    }

    /* Function Name:
     *      rtl_qos_dscpRemark_set
     * Description:
     *      Set DSCP remarking parameter.
     * Input:
     *      int_pri - Internal priority value.
     *      dscp    - DSCP value.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_QOS_INT_PRIORITY - Invalid priority.
     *      RT_ERR_QOS_DSCP_VALUE   - Invalid DSCP value.
     * Note:
     *      The API can set DSCP value and mapping priority.
     */
    rtk_api_ret_t rtl_qos_dscpRemark_set(rtk_pri_t int_pri, rtk_dscp_t dscp)
    {
        return rtk_qos_dscpRemark_set(int_pri, dscp);
    }

    /* Function Name:
     *      rtl_qos_dscpRemark_get
     * Description:
     *      Get DSCP remarking parameter.
     * Input:
     *      int_pri - Internal priority value.
     * Output:
     *      Dscp - DSCP value.
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_QOS_INT_PRIORITY - Invalid priority.
     * Note:
     *      The API can get DSCP parameters. It would return DSCP value for mapping priority.
     */
    rtk_api_ret_t rtl_qos_dscpRemark_get(rtk_pri_t int_pri, rtk_dscp_t *pDscp)
    {
        return rtk_qos_dscpRemark_get(int_pri, pDscp);
    }

    /* Function Name:
     *      rtl_qos_dscpRemarkSrcSel_set
     * Description:
     *      Set remarking source of DSCP remarking.
     * Input:
     *      type      - remarking source
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_NOT_INIT         - The module is not initial
     *      RT_ERR_PORT_ID  - invalid port id
     *      RT_ERR_INPUT            - invalid input parameter

     * Note:
     *      The API can configure DSCP remark functionality to map original DSCP value or internal
     *      priority to TX DSCP value.
     */
    rtk_api_ret_t rtl_qos_dscpRemarkSrcSel_set(rtk_qos_dscpRmkSrc_t type)
    {
        return rtk_qos_dscpRemarkSrcSel_set(type);
    }

    /* Function Name:
     *      rtl_qos_dscpRemarkSrcSel_get
     * Description:
     *      Get remarking source of DSCP remarking.
     * Input:
     *      none
     * Output:
     *      pType      - remarking source
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_NOT_INIT         - The module is not initial
     *      RT_ERR_PORT_ID          - invalid port id
     *      RT_ERR_INPUT            - invalid input parameter
     *      RT_ERR_NULL_POINTER     - input parameter may be null pointer

     * Note:
     *      None
     */
    rtk_api_ret_t rtl_qos_dscpRemarkSrcSel_get(rtk_qos_dscpRmkSrc_t *pType)
    {
        return rtk_qos_dscpRemarkSrcSel_get(pType);
    }

    /* Function Name:
     *      rtl_qos_dscpRemark2Dscp_set
     * Description:
     *      Set DSCP to remarked DSCP mapping.
     * Input:
     *      dscp    - DSCP value
     *      rmkDscp - remarked DSCP value
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_QOS_DSCP_VALUE   - Invalid dscp value
     * Note:
     *      dscp parameter can be DSCP value or internal priority according to configuration of API
     *      dal_apollomp_qos_dscpRemarkSrcSel_set(), because DSCP remark functionality can map original DSCP
     *      value or internal priority to TX DSCP value.
     */
    rtk_api_ret_t rtl_qos_dscpRemark2Dscp_set(rtk_dscp_t dscp, rtk_dscp_t rmkDscp)
    {
        return rtk_qos_dscpRemark2Dscp_set(dscp, rmkDscp);
    }

    /* Function Name:
     *      rtl_qos_dscpRemark2Dscp_get
     * Description:
     *      Get DSCP to remarked DSCP mapping.
     * Input:
     *      dscp    - DSCP value
     * Output:
     *      pDscp   - remarked DSCP value
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_QOS_DSCP_VALUE   - Invalid dscp value
     *      RT_ERR_NULL_POINTER     - NULL pointer
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_qos_dscpRemark2Dscp_get(rtk_dscp_t dscp, rtk_dscp_t *pDscp)
    {
        return rtk_qos_dscpRemark2Dscp_get(dscp, pDscp);
    }

    /* Function Name:
     *      rtl_qos_portPriSelIndex_set
     * Description:
     *      Configure priority decision index to each port.
     * Input:
     *      port - Port id.
     *      index - priority decision index.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_ENTRY_INDEX - Invalid entry index.
     * Note:
     *      The API can set priority of port assignments for queue usage and packet scheduling.
     */
    rtk_api_ret_t rtl_qos_portPriSelIndex_set(rtk_port_t port, rtk_qos_priDecTbl_t index)
    {
        return rtk_qos_portPriSelIndex_set(port, index);
    }

    /* Function Name:
     *      rtl_qos_portPriSelIndex_get
     * Description:
     *      Get priority decision index from each port.
     * Input:
     *      port - Port id.
     * Output:
     *      pIndex - priority decision index.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get priority of port assignments for queue usage and packet scheduling.
     */
    rtk_api_ret_t rtl_qos_portPriSelIndex_get(rtk_port_t port, rtk_qos_priDecTbl_t *pIndex)
    {
        return rtk_qos_portPriSelIndex_get(port, pIndex);
    }
};

#endif