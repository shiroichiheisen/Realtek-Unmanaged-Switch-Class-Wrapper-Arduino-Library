#ifndef _rtl_acl_hpp_
#define _rtl_acl_hpp_

extern "C"
{
#include "acl.h"
#include "rtk_types.h"
}

class rtl_acl
{
public:
    /* Function Name:
     *      rtl_filter_igrAcl_field_add
     * Description:
     *      Add comparison rule to an ACL configuration
     * Input:
     *      pFilter_cfg     - The ACL configuration that this function will add comparison rule
     *      pFilter_field   - The comparison rule that will be added.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_NULL_POINTER     - Pointer pFilter_field or pFilter_cfg point to NULL.
     *      RT_ERR_INPUT            - Invalid input parameters.
     * Note:
     *      This function add a comparison rule (*pFilter_field) to an ACL configuration (*pFilter_cfg).
     *      Pointer pFilter_cfg points to an ACL configuration structure, this structure keeps multiple ACL
     *      comparison rules by means of linked list. Pointer pFilter_field will be added to linked
     *      list keeped by structure that pFilter_cfg points to.
     */
    rtk_api_ret_t rtl_filter_igrAcl_field_add(rtk_filter_cfg_t *pFilter_cfg, rtk_filter_field_t *pFilter_field)
    {
        return rtk_filter_igrAcl_field_add(pFilter_cfg, pFilter_field);
    }

    /* Function Name:
     *      rtl_filter_igrAcl_cfg_add
     * Description:
     *      Add an ACL configuration to ASIC
     * Input:
     *      filter_id       - Start index of ACL configuration.
     *      pFilter_cfg     - The ACL configuration that this function will add comparison rule
     *      pFilter_action  - Action(s) of ACL configuration.
     * Output:
     *      ruleNum - number of rules written in acl table
     * Return:
     *      RT_ERR_OK                               - OK
     *      RT_ERR_FAILED                           - Failed
     *      RT_ERR_SMI                              - SMI access error
     *      RT_ERR_NULL_POINTER                     - Pointer pFilter_field or pFilter_cfg point to NULL.
     *      RT_ERR_INPUT                            - Invalid input parameters.
     *      RT_ERR_ENTRY_INDEX                      - Invalid filter_id .
     *      RT_ERR_NULL_POINTER                     - Pointer pFilter_action or pFilter_cfg point to NULL.
     *      RT_ERR_FILTER_INACL_ACT_NOT_SUPPORT     - Action is not supported in this chip.
     *      RT_ERR_FILTER_INACL_RULE_NOT_SUPPORT    - Rule is not supported.
     * Note:
     *      This function store pFilter_cfg, pFilter_action into ASIC. The starting
     *      index(es) is filter_id.
     */
    rtk_api_ret_t rtl_filter_igrAcl_cfg_add(rtk_filter_id_t filter_id, rtk_filter_cfg_t *pFilter_cfg, rtk_filter_action_t *pAction, rtk_filter_number_t *ruleNum)
    {
        return rtk_filter_igrAcl_cfg_add(filter_id, pFilter_cfg, pAction, ruleNum);
    }

    /* Function Name:
     *      rtl_filter_igrAcl_cfg_del
     * Description:
     *      Delete an ACL configuration from ASIC
     * Input:
     *      filter_id   - Start index of ACL configuration.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_FILTER_ENTRYIDX  - Invalid filter_id.
     * Note:
     *      This function delete a group of ACL rules starting from filter_id.
     */
    rtk_api_ret_t rtl_filter_igrAcl_cfg_del(rtk_filter_id_t filter_id)
    {
        return rtk_filter_igrAcl_cfg_del(filter_id);
    }

    /* Function Name:
     *      rtl_filter_igrAcl_cfg_delAll
     * Description:
     *      Delete all ACL entries from ASIC
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      This function delete all ACL configuration from ASIC.
     */
    rtk_api_ret_t rtl_filter_igrAcl_cfg_delAll()
    {
        return rtk_filter_igrAcl_cfg_delAll();
    }

    /* Function Name:
     *      rtl_filter_igrAcl_cfg_get
     * Description:
     *      Get one ingress acl configuration from ASIC.
     * Input:
     *      filter_id       - Start index of ACL configuration.
     * Output:
     *      pFilter_cfg     - buffer pointer of ingress acl data
     *      pFilter_action  - buffer pointer of ingress acl action
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_NULL_POINTER     - Pointer pFilter_action or pFilter_cfg point to NULL.
     *      RT_ERR_FILTER_ENTRYIDX  - Invalid entry index.
     * Note:
     *      This function delete all ACL configuration from ASIC.
     */
    rtk_api_ret_t rtl_filter_igrAcl_cfg_get(rtk_filter_id_t filter_id, rtk_filter_cfg_raw_t *pFilter_cfg, rtk_filter_action_t *pAction)
    {
        return rtk_filter_igrAcl_cfg_get(filter_id, pFilter_cfg, pAction);
    }

    /* Function Name:
     *      rtl_filter_igrAcl_unmatchAction_set
     * Description:
     *      Set action to packets when no ACL configuration match
     * Input:
     *      port    - Port id.
     *      action  - Action.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port id.
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This function sets action of packets when no ACL configruation matches.
     */
    rtk_api_ret_t rtl_filter_igrAcl_unmatchAction_set(rtk_port_t port, rtk_filter_unmatch_action_t action)
    {
        return rtk_filter_igrAcl_unmatchAction_set(port, action);
    }

    /* Function Name:
     *      rtl_filter_igrAcl_unmatchAction_get
     * Description:
     *      Get action to packets when no ACL configuration match
     * Input:
     *      port    - Port id.
     * Output:
     *      pAction - Action.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port id.
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This function gets action of packets when no ACL configruation matches.
     */
    rtk_api_ret_t rtl_filter_igrAcl_unmatchAction_get(rtk_port_t port, rtk_filter_unmatch_action_t *action)
    {
        return rtk_filter_igrAcl_unmatchAction_get(port, action);
    }

    /* Function Name:
     *      rtl_filter_igrAcl_state_set
     * Description:
     *      Set state of ingress ACL.
     * Input:
     *      port    - Port id.
     *      state   - Ingress ACL state.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port id.
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This function gets action of packets when no ACL configruation matches.
     */
    rtk_api_ret_t rtl_filter_igrAcl_state_set(rtk_port_t port, rtk_filter_state_t state)
    {
        return rtk_filter_igrAcl_state_set(port, state);
    }

    /* Function Name:
     *      rtl_filter_igrAcl_state_get
     * Description:
     *      Get state of ingress ACL.
     * Input:
     *      port    - Port id.
     * Output:
     *      pState  - Ingress ACL state.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port id.
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This function gets action of packets when no ACL configruation matches.
     */
    rtk_api_ret_t rtl_filter_igrAcl_state_get(rtk_port_t port, rtk_filter_state_t *state)
    {
        return rtk_filter_igrAcl_state_get(port, state);
    }

    /* Function Name:
     *      rtl_filter_igrAcl_template_set
     * Description:
     *      Set template of ingress ACL.
     * Input:
     *      template - Ingress ACL template
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Invalid input parameters.
     * Note:
     *      This function set ACL template.
     */
    rtk_api_ret_t rtl_filter_igrAcl_template_set(rtk_filter_template_t *aclTemplate)
    {
        return rtk_filter_igrAcl_template_set(aclTemplate);
    }

    /* Function Name:
     *      rtl_filter_igrAcl_template_get
     * Description:
     *      Get template of ingress ACL.
     * Input:
     *      template - Ingress ACL template
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      This function gets template of ACL.
     */
    rtk_api_ret_t rtl_filter_igrAcl_template_get(rtk_filter_template_t *aclTemplate)
    {
        return rtk_filter_igrAcl_template_get(aclTemplate);
    }

    /* Function Name:
     *      rtl_filter_igrAcl_field_sel_set
     * Description:
     *      Set user defined field selectors in HSB
     * Input:
     *      index       - index of field selector 0-15
     *      format      - Format of field selector
     *      offset      - Retrieving data offset
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      System support 16 user defined field selctors.
     *      Each selector can be enabled or disable.
     *      User can defined retrieving 16-bits in many predefiend
     *      standard l2/l3/l4 payload.
     */
    rtk_api_ret_t rtl_filter_igrAcl_field_sel_set(rtk_uint32 index, rtk_field_sel_t format, rtk_uint32 offset)
    {
        return rtk_filter_igrAcl_field_sel_set(index, format, offset);
    }

    /* Function Name:
     *      rtl_filter_igrAcl_field_sel_get
     * Description:
     *      Get user defined field selectors in HSB
     * Input:
     *      index       - index of field selector 0-15
     * Output:
     *      pFormat     - Format of field selector
     *      pOffset     - Retrieving data offset
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_filter_igrAcl_field_sel_get(rtk_uint32 index, rtk_field_sel_t *pFormat, rtk_uint32 *pOffset)
    {
        return rtk_filter_igrAcl_field_sel_get(index, pFormat, pOffset);
    }

    /* Function Name:
     *      rtl_filter_iprange_set
     * Description:
     *      Set IP Range check
     * Input:
     *      index       - index of IP Range 0-15
     *      type        - IP Range check type, 0:Delete a entry, 1: IPv4_SIP, 2: IPv4_DIP, 3:IPv6_SIP, 4:IPv6_DIP
     *      upperIp     - The upper bound of IP range
     *      lowerIp     - The lower Bound of IP range
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_OUT_OF_RANGE    - The parameter is out of range
     *      RT_ERR_INPUT           - Input error
     * Note:
     *      upperIp must be larger or equal than lowerIp.
     */
    rtk_api_ret_t rtl_filter_iprange_set(rtk_uint32 index, rtk_filter_iprange_t type, ipaddr_t upperIp, ipaddr_t lowerIp)
    {
        return rtk_filter_iprange_set(index, type, upperIp, lowerIp);
    }

    /* Function Name:
     *      rtl_filter_iprange_get
     * Description:
     *      Set IP Range check
     * Input:
     *      index       - index of IP Range 0-15
     * Output:
     *      pType        - IP Range check type, 0:Delete a entry, 1: IPv4_SIP, 2: IPv4_DIP, 3:IPv6_SIP, 4:IPv6_DIP
     *      pUpperIp     - The upper bound of IP range
     *      pLowerIp     - The lower Bound of IP range
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_OUT_OF_RANGE    - The parameter is out of range
     * Note:
     *      upperIp must be larger or equal than lowerIp.
     */
    rtk_api_ret_t rtl_filter_iprange_get(rtk_uint32 index, rtk_filter_iprange_t *pType, ipaddr_t *pUpperIp, ipaddr_t *pLowerIp)
    {
        return rtk_filter_iprange_get(index, pType, pUpperIp, pLowerIp);
    }

    /* Function Name:
     *      rtl_filter_vidrange_set
     * Description:
     *      Set VID Range check
     * Input:
     *      index       - index of VID Range 0-15
     *      type        - IP Range check type, 0:Delete a entry, 1: CVID, 2: SVID
     *      upperVid    - The upper bound of VID range
     *      lowerVid    - The lower Bound of VID range
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_OUT_OF_RANGE    - The parameter is out of range
     *      RT_ERR_INPUT           - Input error
     * Note:
     *      upperVid must be larger or equal than lowerVid.
     */
    rtk_api_ret_t rtl_filter_vidrange_set(rtk_uint32 index, rtk_filter_vidrange_t type, rtk_uint32 upperVid, rtk_uint32 lowerVid)
    {
        return rtk_filter_vidrange_set(index, type, upperVid, lowerVid);
    }

    /* Function Name:
     *      rtl_filter_vidrange_get
     * Description:
     *      Get VID Range check
     * Input:
     *      index       - index of VID Range 0-15
     * Output:
     *      pType        - IP Range check type, 0:Unused, 1: CVID, 2: SVID
     *      pUpperVid    - The upper bound of VID range
     *      pLowerVid    - The lower Bound of VID range
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_OUT_OF_RANGE    - The parameter is out of range
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_filter_vidrange_get(rtk_uint32 index, rtk_filter_vidrange_t *pType, rtk_uint32 *pUpperVid, rtk_uint32 *pLowerVid)
    {
        return rtk_filter_vidrange_get(index, pType, pUpperVid, pLowerVid);
    }

    /* Function Name:
     *      rtl_filter_portrange_set
     * Description:
     *      Set Port Range check
     * Input:
     *      index       - index of Port Range 0-15
     *      type        - IP Range check type, 0:Delete a entry, 1: Source Port, 2: Destnation Port
     *      upperPort   - The upper bound of Port range
     *      lowerPort   - The lower Bound of Port range
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_OUT_OF_RANGE    - The parameter is out of range
     *      RT_ERR_INPUT           - Input error
     * Note:
     *      upperPort must be larger or equal than lowerPort.
     */
    rtk_api_ret_t rtl_filter_portrange_set(rtk_uint32 index, rtk_filter_portrange_t type, rtk_uint32 upperPort, rtk_uint32 lowerPort)
    {
        return rtk_filter_portrange_set(index, type, upperPort, lowerPort);
    }

    /* Function Name:
     *      rtl_filter_portrange_get
     * Description:
     *      Set Port Range check
     * Input:
     *      index       - index of Port Range 0-15
     * Output:
     *      pType       - IP Range check type, 0:Delete a entry, 1: Source Port, 2: Destnation Port
     *      pUpperPort  - The upper bound of Port range
     *      pLowerPort  - The lower Bound of Port range
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_OUT_OF_RANGE    - The parameter is out of range
     *      RT_ERR_INPUT           - Input error
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_filter_portrange_get(rtk_uint32 index, rtk_filter_portrange_t *pType, rtk_uint32 *pUpperPort, rtk_uint32 *pLowerPort)
    {
        return rtk_filter_portrange_get(index, pType, pUpperPort, pLowerPort);
    }

    /* Function Name:
     *      rtl_filter_igrAclPolarity_set
     * Description:
     *      Set ACL Goip control palarity
     * Input:
     *      polarity - 1: High, 0: Low
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Success
     *      RT_ERR_SMI      - SMI access error
     * Note:
     *      none
     */
    rtk_api_ret_t rtl_filter_igrAclPolarity_set(rtk_uint32 polarity)
    {
        return rtk_filter_igrAclPolarity_set(polarity);
    }

    /* Function Name:
     *      rtl_filter_igrAclPolarity_get
     * Description:
     *      Get ACL Goip control palarity
     * Input:
     *      pPolarity - 1: High, 0: Low
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Success
     *      RT_ERR_SMI      - SMI access error
     * Note:
     *      none
     */
    rtk_api_ret_t rtl_filter_igrAclPolarity_get(rtk_uint32 *pPolarity)
    {
        return rtk_filter_igrAclPolarity_get(pPolarity);
    }
};

#endif