#ifndef _rtl_vlan_hpp_
#define _rtl_vlan_hpp_

#include <Arduino.h>

extern "C"
{
#include "vlan.h"
#include "rtk_types.h"
#include "rtk_switch.h"
}

class rtl_vlan
{
public:
    /* Function Name:
     *      rtl_vlan_init
     * Description:
     *      Initialize VLAN.
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      VLAN is disabled by default. User has to call this API to enable VLAN before
     *      using it. And It will set a default VLAN(vid 1) including all ports and set
     *      all ports PVID to the default VLAN.
     */
    rtk_api_ret_t rtl_vlan_init()
    {
        return rtk_vlan_init();
    }

    /* Function Name:
     *      rtl_vlan_set
     * Description:
     *      Set a VLAN entry.
     * Input:
     *      vid - VLAN ID to configure.
     *      pVlanCfg - VLAN Configuration
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_INPUT                - Invalid input parameters.
     *      RT_ERR_L2_FID               - Invalid FID.
     *      RT_ERR_VLAN_PORT_MBR_EXIST  - Invalid member port mask.
     *      RT_ERR_VLAN_VID             - Invalid VID parameter.
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_set(rtk_vlan_t vid, rtk_vlan_cfg_t *pVlanCfg)
    {
        return rtk_vlan_set(vid, pVlanCfg);
    }

    /* Function Name:
     *      rtl_vlan_get
     * Description:
     *      Get a VLAN entry.
     * Input:
     *      vid - VLAN ID to configure.
     * Output:
     *      pVlanCfg - VLAN Configuration
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_VLAN_VID     - Invalid VID parameter.
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_get(rtk_vlan_t vid, rtk_vlan_cfg_t *pVlanCfg)
    {
        return rtk_vlan_get(vid, pVlanCfg);
    }

    /* Function Name:
     *      rtl_vlan_egrFilterEnable_set
     * Description:
     *      Set VLAN egress filter.
     * Input:
     *      egrFilter - Egress filtering
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_ENABLE       - Invalid input parameters.
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_egrFilterEnable_set(rtk_enable_t egrFilter)
    {
        return rtk_vlan_egrFilterEnable_set(egrFilter);
    }

    /* Function Name:
     *      rtl_vlan_egrFilterEnable_get
     * Description:
     *      Get VLAN egress filter.
     * Input:
     *      pEgrFilter - Egress filtering
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_NULL_POINTER - NULL Pointer.
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_egrFilterEnable_get(rtk_enable_t *pEgrFilter)
    {
        return rtk_vlan_egrFilterEnable_get(pEgrFilter);
    }

    /* Function Name:
     *      rtl_vlan_mbrCfg_set
     * Description:
     *      Set a VLAN Member Configuration entry by index.
     * Input:
     *      idx     - Index of VLAN Member Configuration.
     *      pMbrcfg - VLAN member Configuration.
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_VLAN_VID     - Invalid VID parameter.
     * Note:
     *     Set a VLAN Member Configuration entry by index.
     */
    rtk_api_ret_t rtl_vlan_mbrCfg_set(rtk_uint32 idx, rtk_vlan_mbrcfg_t *pMbrcfg)
    {
        return rtk_vlan_mbrCfg_set(idx, pMbrcfg);
    }

    /* Function Name:
     *      rtl_vlan_mbrCfg_get
     * Description:
     *      Get a VLAN Member Configuration entry by index.
     * Input:
     *      idx - Index of VLAN Member Configuration.
     * Output:
     *      pMbrcfg - VLAN member Configuration.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_VLAN_VID     - Invalid VID parameter.
     * Note:
     *     Get a VLAN Member Configuration entry by index.
     */
    rtk_api_ret_t rtl_vlan_mbrCfg_get(rtk_uint32 idx, rtk_vlan_mbrcfg_t *pMbrcfg)
    {
        return rtk_vlan_mbrCfg_get(idx, pMbrcfg);
    }

    /* Function Name:
     *     rtl_vlan_portPvid_set
     * Description:
     *      Set port to specified VLAN ID(PVID).
     * Input:
     *      port - Port id.
     *      pvid - Specified VLAN ID.
     *      priority - 802.1p priority for the PVID.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port number.
     *      RT_ERR_VLAN_PRIORITY        - Invalid priority.
     *      RT_ERR_VLAN_ENTRY_NOT_FOUND - VLAN entry not found.
     *      RT_ERR_VLAN_VID             - Invalid VID parameter.
     * Note:
     *       The API is used for Port-based VLAN. The untagged frame received from the
     *       port will be classified to the specified VLAN and assigned to the specified priority.
     */
    rtk_api_ret_t rtl_vlan_portPvid_set(rtk_port_t port, rtk_vlan_t pvid, rtk_pri_t priority)
    {
        return rtk_vlan_portPvid_set(port, pvid, priority);
    }

    /* Function Name:
     *      rtl_vlan_portPvid_get
     * Description:
     *      Get VLAN ID(PVID) on specified port.
     * Input:
     *      port - Port id.
     * Output:
     *      pPvid - Specified VLAN ID.
     *      pPriority - 802.1p priority for the PVID.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *     The API can get the PVID and 802.1p priority for the PVID of Port-based VLAN.
     */
    rtk_api_ret_t rtl_vlan_portPvid_get(rtk_port_t port, rtk_vlan_t *pPvid, rtk_pri_t *pPriority)
    {
        return rtk_vlan_portPvid_get(port, pPvid, pPriority);
    }

    /* Function Name:
     *      rtl_vlan_portIgrFilterEnable_set
     * Description:
     *      Set VLAN ingress for each port.
     * Input:
     *      port - Port id.
     *      igr_filter - VLAN ingress function enable status.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number
     *      RT_ERR_ENABLE       - Invalid enable input
     * Note:
     *      The status of vlan ingress filter is as following:
     *      - DISABLED
     *      - ENABLED
     *      While VLAN function is enabled, ASIC will decide VLAN ID for each received frame and get belonged member
     *      ports from VLAN table. If received port is not belonged to VLAN member ports, ASIC will drop received frame if VLAN ingress function is enabled.
     */
    rtk_api_ret_t rtl_vlan_portIgrFilterEnable_set(rtk_port_t port, rtk_enable_t igr_filter)
    {
        return rtk_vlan_portIgrFilterEnable_set(port, igr_filter);
    }

    /* Function Name:
     *      rtl_vlan_portIgrFilterEnable_get
     * Description:
     *      Get VLAN Ingress Filter
     * Input:
     *      port        - Port id.
     * Output:
     *      pIgr_filter - VLAN ingress function enable status.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *     The API can Get the VLAN ingress filter status.
     *     The status of vlan ingress filter is as following:
     *     - DISABLED
     *     - ENABLED
     */
    rtk_api_ret_t rtl_vlan_portIgrFilterEnable_get(rtk_port_t port, rtk_enable_t *pIgr_filter)
    {
        return rtk_vlan_portIgrFilterEnable_get(port, pIgr_filter);
    }

    /* Function Name:
     *      rtl_vlan_portAcceptFrameType_set
     * Description:
     *      Set VLAN accept_frame_type
     * Input:
     *      port                - Port id.
     *      accept_frame_type   - accept frame type
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                       - OK
     *      RT_ERR_FAILED                   - Failed
     *      RT_ERR_SMI                      - SMI access error
     *      RT_ERR_PORT_ID                  - Invalid port number.
     *      RT_ERR_VLAN_ACCEPT_FRAME_TYPE   - Invalid frame type.
     * Note:
     *      The API is used for checking 802.1Q tagged frames.
     *      The accept frame type as following:
     *      - ACCEPT_FRAME_TYPE_ALL
     *      - ACCEPT_FRAME_TYPE_TAG_ONLY
     *      - ACCEPT_FRAME_TYPE_UNTAG_ONLY
     */
    rtk_api_ret_t rtl_vlan_portAcceptFrameType_set(rtk_port_t port, rtk_vlan_acceptFrameType_t accept_frame_type)
    {
        return rtk_vlan_portAcceptFrameType_set(port, accept_frame_type);
    }

    /* Function Name:
     *      rtl_vlan_portAcceptFrameType_get
     * Description:
     *      Get VLAN accept_frame_type
     * Input:
     *      port - Port id.
     * Output:
     *      pAccept_frame_type - accept frame type
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *     The API can Get the VLAN ingress filter.
     *     The accept frame type as following:
     *     - ACCEPT_FRAME_TYPE_ALL
     *     - ACCEPT_FRAME_TYPE_TAG_ONLY
     *     - ACCEPT_FRAME_TYPE_UNTAG_ONLY
     */
    rtk_api_ret_t rtl_vlan_portAcceptFrameType_get(rtk_port_t port, rtk_vlan_acceptFrameType_t *pAccept_frame_type)
    {
        return rtk_vlan_portAcceptFrameType_get(port, pAccept_frame_type);
    }

    /* Function Name:
     *      rtl_vlan_tagMode_set
     * Description:
     *      Set CVLAN egress tag mode
     * Input:
     *      port        - Port id.
     *      tag_mode    - The egress tag mode.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_INPUT        - Invalid input parameter.
     *      RT_ERR_ENABLE       - Invalid enable input.
     * Note:
     *      The API can set Egress tag mode. There are 4 mode for egress tag:
     *      - VLAN_TAG_MODE_ORIGINAL,
     *      - VLAN_TAG_MODE_KEEP_FORMAT,
     *      - VLAN_TAG_MODE_PRI.
     *      - VLAN_TAG_MODE_REAL_KEEP_FORMAT,
     */
    rtk_api_ret_t rtl_vlan_tagMode_set(rtk_port_t port, rtk_vlan_tagMode_t tag_mode)
    {
        return rtk_vlan_tagMode_set(port, tag_mode);
    }

    /* Function Name:
     *      rtl_vlan_tagMode_get
     * Description:
     *      Get CVLAN egress tag mode
     * Input:
     *      port - Port id.
     * Output:
     *      pTag_mode - The egress tag mode.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get Egress tag mode. There are 4 mode for egress tag:
     *      - VLAN_TAG_MODE_ORIGINAL,
     *      - VLAN_TAG_MODE_KEEP_FORMAT,
     *      - VLAN_TAG_MODE_PRI.
     *      - VLAN_TAG_MODE_REAL_KEEP_FORMAT,
     */
    rtk_api_ret_t rtl_vlan_tagMode_get(rtk_port_t port, rtk_vlan_tagMode_t *pTag_mode)
    {
        return rtk_vlan_tagMode_get(port, pTag_mode);
    }

    /* Function Name:
     *      rtl_vlan_transparent_set
     * Description:
     *      Set VLAN transparent mode
     * Input:
     *      egr_port        - Egress Port id.
     *      pIgr_pmask      - Ingress Port Mask.
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_vlan_transparent_set(rtk_port_t egr_port, rtk_portmask_t *pIgr_pmask)
    {
        return rtk_vlan_transparent_set(egr_port, pIgr_pmask);
    }

    /* Function Name:
     *      rtl_vlan_transparent_get
     * Description:
     *      Get VLAN transparent mode
     * Input:
     *      egr_port        - Egress Port id.
     * Output:
     *      pIgr_pmask      - Ingress Port Mask
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_vlan_transparent_get(rtk_port_t egr_port, rtk_portmask_t *pIgr_pmask)
    {
        return rtk_vlan_transparent_get(egr_port, pIgr_pmask);
    }

    /* Function Name:
     *      rtl_vlan_keep_set
     * Description:
     *      Set VLAN egress keep mode
     * Input:
     *      egr_port        - Egress Port id.
     *      pIgr_pmask      - Ingress Port Mask.
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_vlan_keep_set(rtk_port_t egr_port, rtk_portmask_t *pIgr_pmask)
    {
        return rtk_vlan_keep_set(egr_port, pIgr_pmask);
    }

    /* Function Name:
     *      rtl_vlan_keep_get
     * Description:
     *      Get VLAN egress keep mode
     * Input:
     *      egr_port        - Egress Port id.
     * Output:
     *      pIgr_pmask      - Ingress Port Mask
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_vlan_keep_get(rtk_port_t egr_port, rtk_portmask_t *pIgr_pmask)
    {
        return rtk_vlan_keep_get(egr_port, pIgr_pmask);
    }

    /* Function Name:
     *      rtl_vlan_stg_set
     * Description:
     *      Set spanning tree group instance of the vlan to the specified device
     * Input:
     *      vid - Specified VLAN ID.
     *      stg - spanning tree group instance.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_MSTI         - Invalid msti parameter
     *      RT_ERR_INPUT        - Invalid input parameter.
     *      RT_ERR_VLAN_VID     - Invalid VID parameter.
     * Note:
     *      The API can set spanning tree group instance of the vlan to the specified device.
     */
    rtk_api_ret_t rtl_vlan_stg_set(rtk_vlan_t vid, rtk_stp_msti_id_t stg)
    {
        return rtk_vlan_stg_set(vid, stg);
    }

    /* Function Name:
     *      rtl_vlan_stg_get
     * Description:
     *      Get spanning tree group instance of the vlan to the specified device
     * Input:
     *      vid - Specified VLAN ID.
     * Output:
     *      pStg - spanning tree group instance.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_VLAN_VID     - Invalid VID parameter.
     * Note:
     *      The API can get spanning tree group instance of the vlan to the specified device.
     */
    rtk_api_ret_t rtl_vlan_stg_get(rtk_vlan_t vid, rtk_stp_msti_id_t *pStg)
    {
        return rtk_vlan_stg_get(vid, pStg);
    }

    /* Function Name:
     *      rtl_vlan_protoAndPortBasedVlan_add
     * Description:
     *      Add the protocol-and-port-based vlan to the specified port of device.
     * Input:
     *      port  - Port id.
     *      pInfo - Protocol and port based VLAN configuration information.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_VLAN_VID         - Invalid VID parameter.
     *      RT_ERR_VLAN_PRIORITY    - Invalid priority.
     *      RT_ERR_TBL_FULL         - Table is full.
     *      RT_ERR_OUT_OF_RANGE     - input out of range.
     * Note:
     *      The incoming packet which match the protocol-and-port-based vlan will use the configure vid for ingress pipeline
     *      The frame type is shown in the following:
     *      - FRAME_TYPE_ETHERNET
     *      - FRAME_TYPE_RFC1042
     *      - FRAME_TYPE_LLCOTHER
     */
    rtk_api_ret_t rtl_vlan_protoAndPortBasedVlan_add(rtk_port_t port, rtk_vlan_protoAndPortInfo_t *pInfo)
    {
        return rtk_vlan_protoAndPortBasedVlan_add(port, pInfo);
    }

    /* Function Name:
     *      rtl_vlan_protoAndPortBasedVlan_get
     * Description:
     *      Get the protocol-and-port-based vlan to the specified port of device.
     * Input:
     *      port - Port id.
     *      proto_type - protocol-and-port-based vlan protocol type.
     *      frame_type - protocol-and-port-based vlan frame type.
     * Output:
     *      pInfo - Protocol and port based VLAN configuration information.
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_OUT_OF_RANGE     - input out of range.
     *      RT_ERR_TBL_FULL         - Table is full.
     * Note:
     *     The incoming packet which match the protocol-and-port-based vlan will use the configure vid for ingress pipeline
     *     The frame type is shown in the following:
     *      - FRAME_TYPE_ETHERNET
     *      - FRAME_TYPE_RFC1042
     *      - FRAME_TYPE_LLCOTHER
     */
    rtk_api_ret_t rtl_vlan_protoAndPortBasedVlan_get(rtk_port_t port, rtk_vlan_proto_type_t proto_type, rtk_vlan_protoVlan_frameType_t frame_type, rtk_vlan_protoAndPortInfo_t *pInfo)
    {
        return rtk_vlan_protoAndPortBasedVlan_get(port, proto_type, frame_type, pInfo);
    }

    /* Function Name:
     *      rtl_vlan_protoAndPortBasedVlan_del
     * Description:
     *      Delete the protocol-and-port-based vlan from the specified port of device.
     * Input:
     *      port        - Port id.
     *      proto_type  - protocol-and-port-based vlan protocol type.
     *      frame_type  - protocol-and-port-based vlan frame type.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_OUT_OF_RANGE     - input out of range.
     *      RT_ERR_TBL_FULL         - Table is full.
     * Note:
     *     The incoming packet which match the protocol-and-port-based vlan will use the configure vid for ingress pipeline
     *     The frame type is shown in the following:
     *      - FRAME_TYPE_ETHERNET
     *      - FRAME_TYPE_RFC1042
     *      - FRAME_TYPE_LLCOTHER
     */
    rtk_api_ret_t rtl_vlan_protoAndPortBasedVlan_del(rtk_port_t port, rtk_vlan_proto_type_t proto_type, rtk_vlan_protoVlan_frameType_t frame_type)
    {
        return rtk_vlan_protoAndPortBasedVlan_del(port, proto_type, frame_type);
    }

    /* Function Name:
     *      rtl_vlan_protoAndPortBasedVlan_delAll
     * Description:
     *     Delete all protocol-and-port-based vlans from the specified port of device.
     * Input:
     *      port - Port id.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_OUT_OF_RANGE     - input out of range.
     * Note:
     *     The incoming packet which match the protocol-and-port-based vlan will use the configure vid for ingress pipeline
     *     Delete all flow table protocol-and-port-based vlan entries.
     */
    rtk_api_ret_t rtl_vlan_protoAndPortBasedVlan_delAll(rtk_port_t port)
    {
        return rtk_vlan_protoAndPortBasedVlan_delAll(port);
    }

    /* Function Name:
     *      rtl_vlan_portFid_set
     * Description:
     *      Set port-based filtering database
     * Input:
     *      port - Port id.
     *      enable - ebable port-based FID
     *      fid - Specified filtering database.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_L2_FID - Invalid fid.
     *      RT_ERR_INPUT - Invalid input parameter.
     *      RT_ERR_PORT_ID - Invalid port ID.
     * Note:
     *      The API can set port-based filtering database. If the function is enabled, all input
     *      packets will be assigned to the port-based fid regardless vlan tag.
     */
    rtk_api_ret_t rtl_vlan_portFid_set(rtk_port_t port, rtk_enable_t enable, rtk_fid_t fid)
    {
        return rtk_vlan_portFid_set(port, enable, fid);
    }

    /* Function Name:
     *      rtl_vlan_portFid_get
     * Description:
     *      Get port-based filtering database
     * Input:
     *      port - Port id.
     * Output:
     *      pEnable - ebable port-based FID
     *      pFid - Specified filtering database.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT - Invalid input parameters.
     *      RT_ERR_PORT_ID - Invalid port ID.
     * Note:
     *      The API can get port-based filtering database status. If the function is enabled, all input
     *      packets will be assigned to the port-based fid regardless vlan tag.
     */
    rtk_api_ret_t rtl_vlan_portFid_get(rtk_port_t port, rtk_enable_t *pEnable, rtk_fid_t *pFid)
    {
        return rtk_vlan_portFid_get(port, pEnable, pFid);
    }

    /* Function Name:
     *      rtl_vlan_UntagDscpPriorityEnable_set
     * Description:
     *      Set Untag DSCP priority assign
     * Input:
     *      enable - state of Untag DSCP priority assign
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_ENABLE          - Invalid input parameters.
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_UntagDscpPriorityEnable_set(rtk_enable_t enable)
    {
        return rtk_vlan_UntagDscpPriorityEnable_set(enable);
    }

    /* Function Name:
     *      rtl_vlan_UntagDscpPriorityEnable_get
     * Description:
     *      Get Untag DSCP priority assign
     * Input:
     *      None
     * Output:
     *      pEnable - state of Untag DSCP priority assign
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_NULL_POINTER    - Null pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_UntagDscpPriorityEnable_get(rtk_enable_t *pEnable)
    {
        return rtk_vlan_UntagDscpPriorityEnable_get(pEnable);
    }

    /*Spanning Tree*/
    /* Function Name:
     *      rtl_stp_mstpState_set
     * Description:
     *      Configure spanning tree state per each port.
     * Input:
     *      port - Port id
     *      msti - Multiple spanning tree instance.
     *      stp_state - Spanning tree state for msti
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_MSTI         - Invalid msti parameter.
     *      RT_ERR_MSTP_STATE   - Invalid STP state.
     * Note:
     *      System supports per-port multiple spanning tree state for each msti.
     *      There are four states supported by ASIC.
     *      - STP_STATE_DISABLED
     *      - STP_STATE_BLOCKING
     *      - STP_STATE_LEARNING
     *      - STP_STATE_FORWARDING
     */
    rtk_api_ret_t rtl_stp_mstpState_set(rtk_stp_msti_id_t msti, rtk_port_t port, rtk_stp_state_t stp_state)
    {
        return rtk_stp_mstpState_set(msti, port, stp_state);
    }

    /* Function Name:
     *      rtl_stp_mstpState_get
     * Description:
     *      Get spanning tree state per each port.
     * Input:
     *      port - Port id.
     *      msti - Multiple spanning tree instance.
     * Output:
     *      pStp_state - Spanning tree state for msti
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_MSTI         - Invalid msti parameter.
     * Note:
     *      System supports per-port multiple spanning tree state for each msti.
     *      There are four states supported by ASIC.
     *      - STP_STATE_DISABLED
     *      - STP_STATE_BLOCKING
     *      - STP_STATE_LEARNING
     *      - STP_STATE_FORWARDING
     */
    rtk_api_ret_t rtl_stp_mstpState_get(rtk_stp_msti_id_t msti, rtk_port_t port, rtk_stp_state_t *pStp_state)
    {
        return rtk_stp_mstpState_get(msti, port, pStp_state);
    }

    /* Function Name:
     *      rtl_vlan_checkAndCreateMbr
     * Description:
     *      Check and create Member configuration and return index
     * Input:
     *      vid  - VLAN id.
     * Output:
     *      pIndex  - Member configuration index
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_VLAN_VID     - Invalid VLAN ID.
     *      RT_ERR_VLAN_ENTRY_NOT_FOUND - VLAN not found
     *      RT_ERR_TBL_FULL     - Member Configuration table full
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_checkAndCreateMbr(rtk_vlan_t vid, rtk_uint32 *pIndex)
    {
        return rtk_vlan_checkAndCreateMbr(vid, pIndex);
    }

    /* Function Name:
     *      rtl_vlan_reservedVidAction_set
     * Description:
     *      Set Action of VLAN ID = 0 & 4095 tagged packet
     * Input:
     *      action_vid0     - Action for VID 0.
     *      action_vid4095  - Action for VID 4095.
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Error Input
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_reservedVidAction_set(rtk_vlan_resVidAction_t action_vid0, rtk_vlan_resVidAction_t action_vid4095)
    {
        return rtk_vlan_reservedVidAction_set(action_vid0, action_vid4095);
    }

    /* Function Name:
     *      rtl_vlan_reservedVidAction_get
     * Description:
     *      Get Action of VLAN ID = 0 & 4095 tagged packet
     * Input:
     *      pAction_vid0     - Action for VID 0.
     *      pAction_vid4095  - Action for VID 4095.
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_NULL_POINTER - NULL Pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_reservedVidAction_get(rtk_vlan_resVidAction_t *pAction_vid0, rtk_vlan_resVidAction_t *pAction_vid4095)
    {
        return rtk_vlan_reservedVidAction_get(pAction_vid0, pAction_vid4095);
    }

    /* Function Name:
     *      rtl_vlan_realKeepRemarkEnable_set
     * Description:
     *      Set Real keep 1p remarking feature
     * Input:
     *      enabled     - State of 1p remarking at real keep packet
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Error Input
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_realKeepRemarkEnable_set(rtk_enable_t enabled)
    {
        return rtk_vlan_realKeepRemarkEnable_set(enabled);
    }

    /* Function Name:
     *      rtl_vlan_realKeepRemarkEnable_get
     * Description:
     *      Get Real keep 1p remarking feature
     * Input:
     *      None.
     * Output:
     *      pEnabled     - State of 1p remarking at real keep packet
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Error Input
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_realKeepRemarkEnable_get(rtk_enable_t *pEnabled)
    {
        return rtk_vlan_realKeepRemarkEnable_get(pEnabled);
    }

    /* Function Name:
     *      rtl_vlan_reset
     * Description:
     *      Reset VLAN
     * Input:
     *      None.
     * Output:
     *      pEnabled     - State of 1p remarking at real keep packet
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Error Input
     * Note:
     *
     */
    rtk_api_ret_t rtl_vlan_reset()
    {
        return rtk_vlan_reset();
    }

    /**
     * @brief Clear VLAN configuration for a specific VLAN ID.
     *
     * This function will clear VLAN configuration for a specific VLAN ID.
     *
     * @param vlanId The VLAN ID to be cleared (0~4095) uint16_t.
     *
     * @return RT_ERR_OK if Success.
     */
    rtk_api_ret_t clearVlan(uint16_t vlanId)
    {
        rtk_vlan_cfg_t vlan1;
        memset(&vlan1, 0x00, sizeof(rtk_vlan_cfg_t));
        RTK_PORTMASK_CLEAR(vlan1.mbr);
        RTK_PORTMASK_CLEAR(vlan1.untag);
        return rtk_vlan_set(vlanId, &vlan1);
    }
};

#endif