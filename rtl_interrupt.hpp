#ifndef _rtl_interrupt_hpp_
#define _rtl_interrupt_hpp_

#include <Arduino.h>

extern "C"
{
#include "interrupt.h"
#include "rtk_types.h"
}

class rtl_interrupt
{
public:
    /* Function Name:
     *      rtl_int_polarity_set
     * Description:
     *      Set interrupt polarity configuration.
     * Input:
     *      type - Interruptpolarity type.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can set interrupt polarity configuration.
     */
    rtk_api_ret_t rtl_int_polarity_set(rtk_int_polarity_t type)
    {
        return rtk_int_polarity_set(type);
    }

    /* Function Name:
     *      rtl_int_polarity_get
     * Description:
     *      Get interrupt polarity configuration.
     * Input:
     *      None
     * Output:
     *      pType - Interruptpolarity type.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      The API can get interrupt polarity configuration.
     */
    rtk_api_ret_t rtl_int_polarity_get(rtk_int_polarity_t *pType)
    {
        return rtk_int_polarity_get(pType);
    }

    /* Function Name:
     *      rtl_int_control_set
     * Description:
     *      Set interrupt trigger status configuration.
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
     *      The API can set interrupt status configuration.
     *      The interrupt trigger status is shown in the following:
     *      - INT_TYPE_LINK_STATUS
     *      - INT_TYPE_METER_EXCEED
     *      - INT_TYPE_LEARN_LIMIT
     *      - INT_TYPE_LINK_SPEED
     *      - INT_TYPE_CONGEST
     *      - INT_TYPE_GREEN_FEATURE
     *      - INT_TYPE_LOOP_DETECT
     *      - INT_TYPE_8051,
     *      - INT_TYPE_CABLE_DIAG,
     *      - INT_TYPE_ACL,
     *      - INT_TYPE_SLIENT
     */
    rtk_api_ret_t rtl_int_control_set(rtk_int_type_t type, rtk_enable_t enable)
    {
        return rtk_int_control_set(type, enable);
    }

    /* Function Name:
     *      rtl_int_control_get
     * Description:
     *      Get interrupt trigger status configuration.
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
     *      - INT_TYPE_LINK_STATUS
     *      - INT_TYPE_METER_EXCEED
     *      - INT_TYPE_LEARN_LIMIT
     *      - INT_TYPE_LINK_SPEED
     *      - INT_TYPE_CONGEST
     *      - INT_TYPE_GREEN_FEATURE
     *      - INT_TYPE_LOOP_DETECT
     *      - INT_TYPE_8051,
     *      - INT_TYPE_CABLE_DIAG,
     *      - INT_TYPE_ACL,
     *      - INT_TYPE_SLIENT
     */
    rtk_api_ret_t rtl_int_control_get(rtk_int_type_t type, rtk_enable_t *pEnable)
    {
        return rtk_int_control_get(type, pEnable);
    }

    /* Function Name:
     *      rtl_int_status_set
     * Description:
     *      Set interrupt trigger status to clean.
     * Input:
     *      None
     * Output:
     *      pStatusMask - Interrupt status bit mask.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT - Invalid input parameters.
     * Note:
     *      The API can clean interrupt trigger status when interrupt happened.
     *      The interrupt trigger status is shown in the following:
     *      - INT_TYPE_LINK_STATUS    (value[0] (Bit0))
     *      - INT_TYPE_METER_EXCEED   (value[0] (Bit1))
     *      - INT_TYPE_LEARN_LIMIT    (value[0] (Bit2))
     *      - INT_TYPE_LINK_SPEED     (value[0] (Bit3))
     *      - INT_TYPE_CONGEST        (value[0] (Bit4))
     *      - INT_TYPE_GREEN_FEATURE  (value[0] (Bit5))
     *      - INT_TYPE_LOOP_DETECT    (value[0] (Bit6))
     *      - INT_TYPE_8051           (value[0] (Bit7))
     *      - INT_TYPE_CABLE_DIAG     (value[0] (Bit8))
     *      - INT_TYPE_ACL            (value[0] (Bit9))
     *      - INT_TYPE_SLIENT         (value[0] (Bit11))
     *      The status will be cleared after execute this API.
     */
    rtk_api_ret_t rtl_int_status_set(rtk_int_status_t *pStatusMask)
    {
        return rtk_int_status_set(pStatusMask);
    }

    /* Function Name:
     *      rtl_int_status_get
     * Description:
     *      Get interrupt trigger status.
     * Input:
     *      None
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
     *      - INT_TYPE_LINK_STATUS    (value[0] (Bit0))
     *      - INT_TYPE_METER_EXCEED   (value[0] (Bit1))
     *      - INT_TYPE_LEARN_LIMIT    (value[0] (Bit2))
     *      - INT_TYPE_LINK_SPEED     (value[0] (Bit3))
     *      - INT_TYPE_CONGEST        (value[0] (Bit4))
     *      - INT_TYPE_GREEN_FEATURE  (value[0] (Bit5))
     *      - INT_TYPE_LOOP_DETECT    (value[0] (Bit6))
     *      - INT_TYPE_8051           (value[0] (Bit7))
     *      - INT_TYPE_CABLE_DIAG     (value[0] (Bit8))
     *      - INT_TYPE_ACL            (value[0] (Bit9))
     *      - INT_TYPE_SLIENT         (value[0] (Bit11))
     *
     */
    rtk_api_ret_t rtl_int_status_get(rtk_int_status_t *pStatusMask)
    {
        return rtk_int_status_get(pStatusMask);
    }

    /* Function Name:
     *      rtl_int_advanceInfo_get
     * Description:
     *      Get interrupt advanced information.
     * Input:
     *      adv_type - Advanced interrupt type.
     * Output:
     *      info - Information per type.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This API can get advanced information when interrupt happened.
     *      The status will be cleared after execute this API.
     */
    rtk_api_ret_t rtl_int_advanceInfo_get(rtk_int_advType_t adv_type, rtk_int_info_t *info)
    {
        return rtk_int_advanceInfo_get(adv_type, info);
    }
};

#endif