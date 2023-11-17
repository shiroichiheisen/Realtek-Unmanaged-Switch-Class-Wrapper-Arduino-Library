#ifndef _rtl_l2_hpp_
#define _rtl_l2_hpp_

#include <Arduino.h>

extern "C"
{
#include "l2.h"
#include "rtk_types.h"
}

class rtl_l2
{
public:
    /* Function Name:
     *      rtl_l2_init
     * Description:
     *      Initialize l2 module of the specified device.
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK          - OK
     *      RT_ERR_FAILED      - Failed
     *      RT_ERR_SMI         - SMI access error
     * Note:
     *      Initialize l2 module before calling any l2 APIs.
     */
    rtk_api_ret_t rtl_l2_init()
    {
        return rtk_l2_init();
    }

    /* Function Name:
     *      rtl_l2_addr_add
     * Description:
     *      Add LUT unicast entry.
     * Input:
     *      pMac - 6 bytes unicast(I/G bit is 0) mac address to be written into LUT.
     *      pL2_data - Unicast entry parameter
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_MAC              - Invalid MAC address.
     *      RT_ERR_L2_FID           - Invalid FID .
     *      RT_ERR_L2_INDEXTBL_FULL - hashed index is full of entries.
     *      RT_ERR_INPUT            - Invalid input parameters.
     * Note:
     *      If the unicast mac address already existed in LUT, it will udpate the status of the entry.
     *      Otherwise, it will find an empty or asic auto learned entry to write. If all the entries
     *      with the same hash value can't be replaced, ASIC will return a RT_ERR_L2_INDEXTBL_FULL error.
     */
    rtk_api_ret_t rtl_l2_addr_add(rtk_mac_t *pMac, rtk_l2_ucastAddr_t *pL2_data)
    {
        return rtk_l2_addr_add(pMac, pL2_data);
    }

    /* Function Name:
     *      rtl_l2_addr_get
     * Description:
     *      Get LUT unicast entry.
     * Input:
     *      pMac    - 6 bytes unicast(I/G bit is 0) mac address to be written into LUT.
     * Output:
     *      pL2_data - Unicast entry parameter
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port number.
     *      RT_ERR_MAC                  - Invalid MAC address.
     *      RT_ERR_L2_FID               - Invalid FID .
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *      If the unicast mac address existed in LUT, it will return the port and fid where
     *      the mac is learned. Otherwise, it will return a RT_ERR_L2_ENTRY_NOTFOUND error.
     */
    rtk_api_ret_t rtl_l2_addr_get(rtk_mac_t *pMac, rtk_l2_ucastAddr_t *pL2_data)
    {
        return rtk_l2_addr_get(pMac, pL2_data);
    }

    /* Function Name:
     *      rtl_l2_addr_next_get
     * Description:
     *      Get Next LUT unicast entry.
     * Input:
     *      read_method     - The reading method.
     *      port            - The port number if the read_metohd is READMETHOD_NEXT_L2UCSPA
     *      pAddress        - The Address ID
     * Output:
     *      pL2_data - Unicast entry parameter
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port number.
     *      RT_ERR_MAC                  - Invalid MAC address.
     *      RT_ERR_L2_FID               - Invalid FID .
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *      Get the next unicast entry after the current entry pointed by pAddress.
     *      The address of next entry is returned by pAddress. User can use (address + 1)
     *      as pAddress to call this API again for dumping all entries is LUT.
     */
    rtk_api_ret_t rtl_l2_addr_next_get(rtk_l2_read_method_t read_method, rtk_port_t port, rtk_uint32 *pAddress, rtk_l2_ucastAddr_t *pL2_data)
    {
        return rtk_l2_addr_next_get(read_method, port, pAddress, pL2_data);
    }

    /* Function Name:
     *      rtl_l2_addr_del
     * Description:
     *      Delete LUT unicast entry.
     * Input:
     *      pMac - 6 bytes unicast(I/G bit is 0) mac address to be written into LUT.
     *      fid - Filtering database
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port number.
     *      RT_ERR_MAC                  - Invalid MAC address.
     *      RT_ERR_L2_FID               - Invalid FID .
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *      If the mac has existed in the LUT, it will be deleted. Otherwise, it will return RT_ERR_L2_ENTRY_NOTFOUND.
     */
    rtk_api_ret_t rtl_l2_addr_del(rtk_mac_t *pMac, rtk_l2_ucastAddr_t *pL2_data)
    {
        return rtk_l2_addr_del(pMac, pL2_data);
    }

    /* Function Name:
     *      rtl_l2_mcastAddr_add
     * Description:
     *      Add LUT multicast entry.
     * Input:
     *      pMcastAddr  - L2 multicast entry structure
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_MAC              - Invalid MAC address.
     *      RT_ERR_L2_FID           - Invalid FID .
     *      RT_ERR_L2_VID           - Invalid VID .
     *      RT_ERR_L2_INDEXTBL_FULL - hashed index is full of entries.
     *      RT_ERR_PORT_MASK        - Invalid portmask.
     *      RT_ERR_INPUT            - Invalid input parameters.
     * Note:
     *      If the multicast mac address already existed in the LUT, it will udpate the
     *      port mask of the entry. Otherwise, it will find an empty or asic auto learned
     *      entry to write. If all the entries with the same hash value can't be replaced,
     *      ASIC will return a RT_ERR_L2_INDEXTBL_FULL error.
     */
    rtk_api_ret_t rtl_l2_mcastAddr_add(rtk_l2_mcastAddr_t *pMcastAddr)
    {
        return rtk_l2_mcastAddr_add(pMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_mcastAddr_get
     * Description:
     *      Get LUT multicast entry.
     * Input:
     *      pMcastAddr  - L2 multicast entry structure
     * Output:
     *      pMcastAddr  - L2 multicast entry structure
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_MAC                  - Invalid MAC address.
     *      RT_ERR_L2_FID               - Invalid FID .
     *      RT_ERR_L2_VID               - Invalid VID .
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *      If the multicast mac address existed in the LUT, it will return the port where
     *      the mac is learned. Otherwise, it will return a RT_ERR_L2_ENTRY_NOTFOUND error.
     */
    rtk_api_ret_t rtl_l2_mcastAddr_get(rtk_l2_mcastAddr_t *pMcastAddr)
    {
        return rtk_l2_mcastAddr_get(pMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_mcastAddr_next_get
     * Description:
     *      Get Next L2 Multicast entry.
     * Input:
     *      pAddress        - The Address ID
     * Output:
     *      pMcastAddr  - L2 multicast entry structure
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *      Get the next L2 multicast entry after the current entry pointed by pAddress.
     *      The address of next entry is returned by pAddress. User can use (address + 1)
     *      as pAddress to call this API again for dumping all multicast entries is LUT.
     */
    rtk_api_ret_t rtl_l2_mcastAddr_next_get(rtk_uint32 *pAddress, rtk_l2_mcastAddr_t *pMcastAddr)
    {
        return rtk_l2_mcastAddr_next_get(pAddress, pMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_mcastAddr_del
     * Description:
     *      Delete LUT multicast entry.
     * Input:
     *      pMcastAddr  - L2 multicast entry structure
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_MAC                  - Invalid MAC address.
     *      RT_ERR_L2_FID               - Invalid FID .
     *      RT_ERR_L2_VID               - Invalid VID .
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *      If the mac has existed in the LUT, it will be deleted. Otherwise, it will return RT_ERR_L2_ENTRY_NOTFOUND.
     */
    rtk_api_ret_t rtl_l2_mcastAddr_del(rtk_l2_mcastAddr_t *pMcastAddr)
    {
        return rtk_l2_mcastAddr_del(pMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_ipMcastAddr_add
     * Description:
     *      Add Lut IP multicast entry
     * Input:
     *      pIpMcastAddr    - IP Multicast entry
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_L2_INDEXTBL_FULL - hashed index is full of entries.
     *      RT_ERR_PORT_MASK        - Invalid portmask.
     *      RT_ERR_INPUT            - Invalid input parameters.
     * Note:
     *      System supports L2 entry with IP multicast DIP/SIP to forward IP multicasting frame as user
     *      desired. If this function is enabled, then system will be looked up L2 IP multicast entry to
     *      forward IP multicast frame directly without flooding.
     */
    rtk_api_ret_t rtl_l2_ipMcastAddr_add(rtk_l2_ipMcastAddr_t *pIpMcastAddr)
    {
        return rtk_l2_ipMcastAddr_add(pIpMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_ipMcastAddr_get
     * Description:
     *      Get LUT IP multicast entry.
     * Input:
     *      pIpMcastAddr    - IP Multicast entry
     * Output:
     *      pIpMcastAddr    - IP Multicast entry
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *      The API can get Lut table of IP multicast entry.
     */
    rtk_api_ret_t rtl_l2_ipMcastAddr_get(rtk_l2_ipMcastAddr_t *pIpMcastAddr)
    {
        return rtk_l2_ipMcastAddr_get(pIpMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_ipMcastAddr_next_get
     * Description:
     *      Get Next IP Multicast entry.
     * Input:
     *      pAddress        - The Address ID
     * Output:
     *      pIpMcastAddr    - IP Multicast entry
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *      Get the next IP multicast entry after the current entry pointed by pAddress.
     *      The address of next entry is returned by pAddress. User can use (address + 1)
     *      as pAddress to call this API again for dumping all IP multicast entries is LUT.
     */
    rtk_api_ret_t rtl_l2_ipMcastAddr_next_get(rtk_uint32 *pAddress, rtk_l2_ipMcastAddr_t *pIpMcastAddr)
    {
        return rtk_l2_ipMcastAddr_next_get(pAddress, pIpMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_ipMcastAddr_del
     * Description:
     *      Delete a ip multicast address entry from the specified device.
     * Input:
     *      pIpMcastAddr    - IP Multicast entry
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *      The API can delete a IP multicast address entry from the specified device.
     */
    rtk_api_ret_t rtl_l2_ipMcastAddr_del(rtk_l2_ipMcastAddr_t *pIpMcastAddr)
    {
        return rtk_l2_ipMcastAddr_del(pIpMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_ipVidMcastAddr_add
     * Description:
     *      Add Lut IP multicast+VID entry
     * Input:
     *      pIpVidMcastAddr - IP & VID multicast Entry
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_L2_INDEXTBL_FULL - hashed index is full of entries.
     *      RT_ERR_PORT_MASK        - Invalid portmask.
     *      RT_ERR_INPUT            - Invalid input parameters.
     * Note:
     *
     */
    rtk_api_ret_t rtl_l2_ipVidMcastAddr_add(rtk_l2_ipVidMcastAddr_t *pIpVidMcastAddr)
    {
        return rtk_l2_ipVidMcastAddr_add(pIpVidMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_ipVidMcastAddr_get
     * Description:
     *      Get LUT IP multicast+VID entry.
     * Input:
     *      pIpVidMcastAddr - IP & VID multicast Entry
     * Output:
     *      pIpVidMcastAddr - IP & VID multicast Entry
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *
     */
    rtk_api_ret_t rtl_l2_ipVidMcastAddr_get(rtk_l2_ipVidMcastAddr_t *pIpVidMcastAddr)
    {
        return rtk_l2_ipVidMcastAddr_get(pIpVidMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_ipVidMcastAddr_next_get
     * Description:
     *      Get Next IP Multicast+VID entry.
     * Input:
     *      pAddress        - The Address ID
     * Output:
     *      pIpVidMcastAddr - IP & VID multicast Entry
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *      Get the next IP multicast entry after the current entry pointed by pAddress.
     *      The address of next entry is returned by pAddress. User can use (address + 1)
     *      as pAddress to call this API again for dumping all IP multicast entries is LUT.
     */
    rtk_api_ret_t rtl_l2_ipVidMcastAddr_next_get(rtk_uint32 *pAddress, rtk_l2_ipVidMcastAddr_t *pIpVidMcastAddr)
    {
        return rtk_l2_ipVidMcastAddr_next_get(pAddress, pIpVidMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_ipVidMcastAddr_del
     * Description:
     *      Delete a ip multicast+VID address entry from the specified device.
     * Input:
     *      pIpVidMcastAddr - IP & VID multicast Entry
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_L2_ENTRY_NOTFOUND    - No such LUT entry.
     *      RT_ERR_INPUT                - Invalid input parameters.
     * Note:
     *
     */
    rtk_api_ret_t rtl_l2_ipVidMcastAddr_del(rtk_l2_ipVidMcastAddr_t *pIpVidMcastAddr)
    {
        return rtk_l2_ipVidMcastAddr_del(pIpVidMcastAddr);
    }

    /* Function Name:
     *      rtl_l2_ucastAddr_flush
     * Description:
     *      Flush L2 mac address by type in the specified device (both dynamic and static).
     * Input:
     *      pConfig - flush configuration
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_VLAN_VID     - Invalid VID parameter.
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      flushByVid          - 1: Flush by VID, 0: Don't flush by VID
     *      vid                 - VID (0 ~ 4095)
     *      flushByFid          - 1: Flush by FID, 0: Don't flush by FID
     *      fid                 - FID (0 ~ 15)
     *      flushByPort         - 1: Flush by Port, 0: Don't flush by Port
     *      port                - Port ID
     *      flushByMac          - Not Supported
     *      ucastAddr           - Not Supported
     *      flushStaticAddr     - 1: Flush both Static and Dynamic entries, 0: Flush only Dynamic entries
     *      flushAddrOnAllPorts - 1: Flush VID-matched entries at all ports, 0: Flush VID-matched entries per port.
     */
    rtk_api_ret_t rtl_l2_ucastAddr_flush(rtk_l2_flushCfg_t *pConfig)
    {
        return rtk_l2_ucastAddr_flush(pConfig);
    }

    /* Function Name:
     *      rtl_l2_table_clear
     * Description:
     *      Flush all static & dynamic entries in LUT.
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
    rtk_api_ret_t rtl_l2_table_clear()
    {
        return rtk_l2_table_clear();
    }

    /* Function Name:
     *      rtl_l2_table_clearStatus_get
     * Description:
     *      Get table clear status
     * Input:
     *      None
     * Output:
     *      pStatus - Clear status, 1:Busy, 0:finish
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *
     */
    rtk_api_ret_t rtl_l2_table_clearStatus_get(rtk_l2_clearStatus_t *pStatus)
    {
        return rtk_l2_table_clearStatus_get(pStatus);
    }

    /* Function Name:
     *      rtl_l2_flushLinkDownPortAddrEnable_set
     * Description:
     *      Set HW flush linkdown port mac configuration of the specified device.
     * Input:
     *      port - Port id.
     *      enable - link down flush status
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_ENABLE       - Invalid enable input.
     * Note:
     *      The status of flush linkdown port address is as following:
     *      - DISABLED
     *      - ENABLED
     */
    rtk_api_ret_t rtl_l2_flushLinkDownPortAddrEnable_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_l2_flushLinkDownPortAddrEnable_set(port, enable);
    }

    /* Function Name:
     *      rtl_l2_flushLinkDownPortAddrEnable_get
     * Description:
     *      Get HW flush linkdown port mac configuration of the specified device.
     * Input:
     *      port - Port id.
     * Output:
     *      pEnable - link down flush status
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The status of flush linkdown port address is as following:
     *      - DISABLED
     *      - ENABLED
     */
    rtk_api_ret_t rtl_l2_flushLinkDownPortAddrEnable_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_l2_flushLinkDownPortAddrEnable_get(port, pEnable);
    }

    /* Function Name:
     *      rtl_l2_agingEnable_set
     * Description:
     *      Set L2 LUT aging status per port setting.
     * Input:
     *      port    - Port id.
     *      enable  - Aging status
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_ENABLE       - Invalid enable input.
     * Note:
     *      This API can be used to set L2 LUT aging status per port.
     */
    rtk_api_ret_t rtl_l2_agingEnable_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_l2_agingEnable_set(port, enable);
    }

    /* Function Name:
     *      rtl_l2_agingEnable_get
     * Description:
     *      Get L2 LUT aging status per port setting.
     * Input:
     *      port - Port id.
     * Output:
     *      pEnable - Aging status
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      This API can be used to get L2 LUT aging function per port.
     */
    rtk_api_ret_t rtl_l2_agingEnable_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_l2_agingEnable_get(port, pEnable);
    }

    /* Function Name:
     *      rtl_l2_limitLearningCnt_set
     * Description:
     *      Set per-Port auto learning limit number
     * Input:
     *      port    - Port id.
     *      mac_cnt - Auto learning entries limit number
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port number.
     *      RT_ERR_LIMITED_L2ENTRY_NUM  - Invalid auto learning limit number
     * Note:
     *      The API can set per-port ASIC auto learning limit number from 0(disable learning)
     *      to 8k.
     */
    rtk_api_ret_t rtl_l2_limitLearningCnt_set(rtk_port_t port, rtk_mac_cnt_t mac_cnt)
    {
        return rtk_l2_limitLearningCnt_set(port, mac_cnt);
    }

    /* Function Name:
     *      rtl_l2_limitLearningCnt_get
     * Description:
     *      Get per-Port auto learning limit number
     * Input:
     *      port - Port id.
     * Output:
     *      pMac_cnt - Auto learning entries limit number
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get per-port ASIC auto learning limit number.
     */
    rtk_api_ret_t rtl_l2_limitLearningCnt_get(rtk_port_t port, rtk_mac_cnt_t *pMac_cnt)
    {
        return rtk_l2_limitLearningCnt_get(port, pMac_cnt);
    }

    /* Function Name:
     *      rtl_l2_limitSystemLearningCnt_set
     * Description:
     *      Set System auto learning limit number
     * Input:
     *      mac_cnt - Auto learning entries limit number
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_LIMITED_L2ENTRY_NUM  - Invalid auto learning limit number
     * Note:
     *      The API can set system ASIC auto learning limit number from 0(disable learning)
     *      to 2112.
     */
    rtk_api_ret_t rtl_l2_limitSystemLearningCnt_set(rtk_mac_cnt_t mac_cnt)
    {
        return rtk_l2_limitSystemLearningCnt_set(mac_cnt);
    }

    /* Function Name:
     *      rtl_l2_limitSystemLearningCnt_get
     * Description:
     *      Get System auto learning limit number
     * Input:
     *      None
     * Output:
     *      pMac_cnt - Auto learning entries limit number
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get system ASIC auto learning limit number.
     */
    rtk_api_ret_t rtl_l2_limitSystemLearningCnt_get(rtk_mac_cnt_t *pMac_cnt)
    {
        return rtk_l2_limitSystemLearningCnt_get(pMac_cnt);
    }

    /* Function Name:
     *      rtl_l2_limitLearningCntAction_set
     * Description:
     *      Configure auto learn over limit number action.
     * Input:
     *      port - Port id.
     *      action - Auto learning entries limit number
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_NOT_ALLOWED  - Invalid learn over action
     * Note:
     *      The API can set SA unknown packet action while auto learn limit number is over
     *      The action symbol as following:
     *      - LIMIT_LEARN_CNT_ACTION_DROP,
     *      - LIMIT_LEARN_CNT_ACTION_FORWARD,
     *      - LIMIT_LEARN_CNT_ACTION_TO_CPU,
     */
    rtk_api_ret_t rtl_l2_limitLearningCntAction_set(rtk_port_t port, rtk_l2_limitLearnCntAction_t action)
    {
        return rtk_l2_limitLearningCntAction_set(port, action);
    }

    /* Function Name:
     *      rtl_l2_limitLearningCntAction_get
     * Description:
     *      Get auto learn over limit number action.
     * Input:
     *      port - Port id.
     * Output:
     *      pAction - Learn over action
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get SA unknown packet action while auto learn limit number is over
     *      The action symbol as following:
     *      - LIMIT_LEARN_CNT_ACTION_DROP,
     *      - LIMIT_LEARN_CNT_ACTION_FORWARD,
     *      - LIMIT_LEARN_CNT_ACTION_TO_CPU,
     */
    rtk_api_ret_t rtl_l2_limitLearningCntAction_get(rtk_port_t port, rtk_l2_limitLearnCntAction_t *pAction)
    {
        return rtk_l2_limitLearningCntAction_get(port, pAction);
    }

    /* Function Name:
     *      rtl_l2_limitSystemLearningCntAction_set
     * Description:
     *      Configure system auto learn over limit number action.
     * Input:
     *      port - Port id.
     *      action - Auto learning entries limit number
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_NOT_ALLOWED  - Invalid learn over action
     * Note:
     *      The API can set SA unknown packet action while auto learn limit number is over
     *      The action symbol as following:
     *      - LIMIT_LEARN_CNT_ACTION_DROP,
     *      - LIMIT_LEARN_CNT_ACTION_FORWARD,
     *      - LIMIT_LEARN_CNT_ACTION_TO_CPU,
     */
    rtk_api_ret_t rtl_l2_limitSystemLearningCntAction_set(rtk_l2_limitLearnCntAction_t action)
    {
        return rtk_l2_limitSystemLearningCntAction_set(action);
    }

    /* Function Name:
     *      rtl_l2_limitSystemLearningCntAction_get
     * Description:
     *      Get system auto learn over limit number action.
     * Input:
     *      None.
     * Output:
     *      pAction - Learn over action
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get SA unknown packet action while auto learn limit number is over
     *      The action symbol as following:
     *      - LIMIT_LEARN_CNT_ACTION_DROP,
     *      - LIMIT_LEARN_CNT_ACTION_FORWARD,
     *      - LIMIT_LEARN_CNT_ACTION_TO_CPU,
     */
    rtk_api_ret_t rtl_l2_limitSystemLearningCntAction_get(rtk_l2_limitLearnCntAction_t *pAction)
    {
        return rtk_l2_limitSystemLearningCntAction_get(pAction);
    }

    /* Function Name:
     *      rtl_l2_limitSystemLearningCntPortMask_set
     * Description:
     *      Configure system auto learn portmask
     * Input:
     *      pPortmask - Port Mask
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_MASK    - Invalid port mask.
     * Note:
     *
     */
    rtk_api_ret_t rtl_l2_limitSystemLearningCntPortMask_set(rtk_portmask_t *pPortmask)
    {
        return rtk_l2_limitSystemLearningCntPortMask_set(pPortmask);
    }

    /* Function Name:
     *      rtl_l2_limitSystemLearningCntPortMask_get
     * Description:
     *      get system auto learn portmask
     * Input:
     *      None
     * Output:
     *      pPortmask - Port Mask
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_NULL_POINTER - Null pointer.
     * Note:
     *
     */
    rtk_api_ret_t rtl_l2_limitSystemLearningCntPortMask_get(rtk_portmask_t *pPortmask)
    {
        return rtk_l2_limitSystemLearningCntPortMask_get(pPortmask);
    }

    /* Function Name:
     *      rtl_l2_learningCnt_get
     * Description:
     *      Get per-Port current auto learning number
     * Input:
     *      port - Port id.
     * Output:
     *      pMac_cnt - ASIC auto learning entries number
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get per-port ASIC auto learning number
     */
    rtk_api_ret_t rtl_l2_learningCnt_get(rtk_port_t port, rtk_mac_cnt_t *pMac_cnt)
    {
        return rtk_l2_learningCnt_get(port, pMac_cnt);
    }

    /* Function Name:
     *      rtl_l2_floodPortMask_set
     * Description:
     *      Set flooding portmask
     * Input:
     *      type - flooding type.
     *      pFlood_portmask - flooding porkmask
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_MASK    - Invalid portmask.
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This API can set the flooding mask.
     *      The flooding type is as following:
     *      - FLOOD_UNKNOWNDA
     *      - FLOOD_UNKNOWNMC
     *      - FLOOD_BC
     */
    rtk_api_ret_t rtl_l2_floodPortMask_set(rtk_l2_flood_type_t floood_type, rtk_portmask_t *pFlood_portmask)
    {
        return rtk_l2_floodPortMask_set(floood_type, pFlood_portmask);
    }

    /* Function Name:
     *      rtl_l2_floodPortMask_get
     * Description:
     *      Get flooding portmask
     * Input:
     *      type - flooding type.
     * Output:
     *      pFlood_portmask - flooding porkmask
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      This API can get the flooding mask.
     *      The flooding type is as following:
     *      - FLOOD_UNKNOWNDA
     *      - FLOOD_UNKNOWNMC
     *      - FLOOD_BC
     */
    rtk_api_ret_t rtl_l2_floodPortMask_get(rtk_l2_flood_type_t floood_type, rtk_portmask_t *pFlood_portmask)
    {
        return rtk_l2_floodPortMask_get(floood_type, pFlood_portmask);
    }

    /* Function Name:
     *      rtl_l2_localPktPermit_set
     * Description:
     *      Set permittion of frames if source port and destination port are the same.
     * Input:
     *      port - Port id.
     *      permit - permittion status
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_ENABLE       - Invalid permit value.
     * Note:
     *      This API is setted to permit frame if its source port is equal to destination port.
     */
    rtk_api_ret_t rtl_l2_localPktPermit_set(rtk_port_t port, rtk_enable_t permit)
    {
        return rtk_l2_localPktPermit_set(port, permit);
    }

    /* Function Name:
     *      rtl_l2_localPktPermit_get
     * Description:
     *      Get permittion of frames if source port and destination port are the same.
     * Input:
     *      port - Port id.
     * Output:
     *      pPermit - permittion status
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      This API is to get permittion status for frames if its source port is equal to destination port.
     */
    rtk_api_ret_t rtl_l2_localPktPermit_get(rtk_port_t port, rtk_enable_t *pPermit)
    {
        return rtk_l2_localPktPermit_get(port, pPermit);
    }

    /* Function Name:
     *      rtl_l2_aging_set
     * Description:
     *      Set LUT agging out speed
     * Input:
     *      aging_time - Agging out time.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_OUT_OF_RANGE     - input out of range.
     * Note:
     *      The API can set LUT agging out period for each entry and the range is from 14s to 800s.
     */
    rtk_api_ret_t rtl_l2_aging_set(rtk_l2_age_time_t aging_time)
    {
        return rtk_l2_aging_set(aging_time);
    }

    /* Function Name:
     *      rtl_l2_aging_get
     * Description:
     *      Get LUT agging out time
     * Input:
     *      None
     * Output:
     *      pEnable - Aging status
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get LUT agging out period for each entry.
     */
    rtk_api_ret_t rtl_l2_aging_get(rtk_l2_age_time_t *pAging_time)
    {
        return rtk_l2_aging_get(pAging_time);
    }

    /* Function Name:
     *      rtl_l2_ipMcastAddrLookup_set
     * Description:
     *      Set Lut IP multicast lookup function
     * Input:
     *      type - Lookup type for IPMC packet.
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK          - OK
     *      RT_ERR_FAILED      - Failed
     *      RT_ERR_SMI         - SMI access error
     * Note:
     *      This API can work with rtk_l2_ipMcastAddrLookupException_add.
     *      If users set the lookup type to DIP, the group in exception table
     *      will be lookup by DIP+SIP
     *      If users set the lookup type to DIP+SIP, the group in exception table
     *      will be lookup by only DIP
     */
    rtk_api_ret_t rtl_l2_ipMcastAddrLookup_set(rtk_l2_ipmc_lookup_type_t type)
    {
        return rtk_l2_ipMcastAddrLookup_set(type);
    }

    /* Function Name:
     *      rtl_l2_ipMcastAddrLookup_get
     * Description:
     *      Get Lut IP multicast lookup function
     * Input:
     *      None.
     * Output:
     *      pType - Lookup type for IPMC packet.
     * Return:
     *      RT_ERR_OK          - OK
     *      RT_ERR_FAILED      - Failed
     *      RT_ERR_SMI         - SMI access error
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_l2_ipMcastAddrLookup_get(rtk_l2_ipmc_lookup_type_t *pType)
    {
        return rtk_l2_ipMcastAddrLookup_get(pType);
    }

    /* Function Name:
     *      rtl_l2_ipMcastForwardRouterPort_set
     * Description:
     *      Set IPMC packet forward to rounter port also or not
     * Input:
     *      enabled - 1: Inlcude router port, 0, exclude router port
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK          - OK
     *      RT_ERR_FAILED      - Failed
     *      RT_ERR_SMI         - SMI access error
     * Note:
     *
     */
    rtk_api_ret_t rtl_l2_ipMcastForwardRouterPort_set(rtk_enable_t enabled)
    {
        return rtk_l2_ipMcastForwardRouterPort_set(enabled);
    }

    /* Function Name:
     *      rtl_l2_ipMcastForwardRouterPort_get
     * Description:
     *      Get IPMC packet forward to rounter port also or not
     * Input:
     *      None.
     * Output:
     *      pEnabled    - 1: Inlcude router port, 0, exclude router port
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_NULL_POINTER - Null pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_l2_ipMcastForwardRouterPort_get(rtk_enable_t *pEnabled)
    {
        return rtk_l2_ipMcastForwardRouterPort_get(pEnabled);
    }

    /* Function Name:
     *      rtl_l2_ipMcastGroupEntry_add
     * Description:
     *      Add an IP Multicast entry to group table
     * Input:
     *      ip_addr     - IP address
     *      vid         - VLAN ID
     *      pPortmask   - portmask
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK          - OK
     *      RT_ERR_FAILED      - Failed
     *      RT_ERR_SMI         - SMI access error
     *      RT_ERR_TBL_FULL    - Table Full
     * Note:
     *      Add an entry to IP Multicast Group table.
     */
    rtk_api_ret_t rtl_l2_ipMcastGroupEntry_add(ipaddr_t ip_addr, rtk_uint32 vid, rtk_portmask_t *pPortmask)
    {
        return rtk_l2_ipMcastGroupEntry_add(ip_addr, vid, pPortmask);
    }

    /* Function Name:
     *      rtl_l2_ipMcastGroupEntry_del
     * Description:
     *      Delete an entry from IP Multicast group table
     * Input:
     *      ip_addr     - IP address
     *      vid         - VLAN ID
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK          - OK
     *      RT_ERR_FAILED      - Failed
     *      RT_ERR_SMI         - SMI access error
     *      RT_ERR_TBL_FULL    - Table Full
     * Note:
     *      Delete an entry from IP Multicast group table.
     */
    rtk_api_ret_t rtl_l2_ipMcastGroupEntry_del(ipaddr_t ip_addr, rtk_uint32 vid)
    {
        return rtk_l2_ipMcastGroupEntry_del(ip_addr, vid);
    }

    /* Function Name:
     *      rtl_l2_ipMcastGroupEntry_get
     * Description:
     *      get an entry from IP Multicast group table
     * Input:
     *      ip_addr     - IP address
     *      vid         - VLAN ID
     * Output:
     *      pPortmask   - member port mask
     * Return:
     *      RT_ERR_OK          - OK
     *      RT_ERR_FAILED      - Failed
     *      RT_ERR_SMI         - SMI access error
     *      RT_ERR_TBL_FULL    - Table Full
     * Note:
     *      Delete an entry from IP Multicast group table.
     */
    rtk_api_ret_t rtl_l2_ipMcastGroupEntry_get(ipaddr_t ip_addr, rtk_uint32 vid, rtk_portmask_t *pPortmask)
    {
        return rtk_l2_ipMcastGroupEntry_get(ip_addr, vid, pPortmask);
    }

    /* Function Name:
     *      rtl_l2_entry_get
     * Description:
     *      Get LUT unicast entry.
     * Input:
     *      pL2_entry - Index field in the structure.
     * Output:
     *      pL2_entry - other fields such as MAC, port, age...
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_L2_EMPTY_ENTRY   - Empty LUT entry.
     *      RT_ERR_INPUT            - Invalid input parameters.
     * Note:
     *      This API is used to get address by index from 0~2111.
     */
    rtk_api_ret_t rtl_l2_entry_get(rtk_l2_addr_table_t *pL2_entry)
    {
        return rtk_l2_entry_get(pL2_entry);
    }
};

#endif