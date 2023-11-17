#ifndef _rtl_api_hpp_
#define _rtl_api_hpp_

#include <Arduino.h>

#include "rtl_acl.hpp"
#include "rtl_cpu.hpp"
#include "rtl_dot1x.hpp"
#include "rtl_eee.hpp"
#include "rtl_i2c.hpp"
#include "rtl_igmp.hpp"
#include "rtl_interrupt.hpp"
#include "rtl_l2.hpp"
#include "rtl_leaky.hpp"
#include "rtl_led.hpp"
#include "rtl_mirror.hpp"
#include "rtl_oam.hpp"
#include "rtl_port.hpp"
#include "rtl_ptp.hpp"
#include "rtl_qos.hpp"
#include "rtl_rate.hpp"
#include "rtl_rldp.hpp"
#include "rtl_stat.hpp"
#include "rtl_storm.hpp"
#include "rtl_svlan.hpp"
#include "rtl_switch.hpp"
#include "rtl_trap.hpp"
#include "rtl_trunk.hpp"
#include "rtl_vlan.hpp"

extern "C"
{
#include "smi.c"
#include "rtk_error.h"
#include "rtk_types.h"
#include "rtl8367c_asicdrv.h"
}

class rtl_api
{
public:
    rtl_acl acl;
    rtl_cpu cpu;
    rtl_dot1x dot1x;
    rtl_eee eee;
    rtl_i2c i2c;
    rtl_igmp igmp;
    rtl_interrupt interrupt;
    rtl_l2 l2;
    rtl_leaky leaky;
    rtl_led led;
    rtl_mirror mirror;
    rtl_oam oam;
    rtl_port port;
    rtl_ptp ptp;
    rtl_qos qos;
    rtl_rate rate;
    rtl_rldp rldp;
    rtl_stat stat;
    rtl_storm storm;
    rtl_svlan svlan;
    rtl_switch switch_;
    rtl_trap trap;
    rtl_trunk trunk;
    rtl_vlan vlan;

    void changeI2cPins(uint8_t sda, uint8_t scl)
    {
        RTK_I2C_SCK_PIN = scl;
        RTK_I2C_SDA_PIN = sda;
    }

    void changeI2cDelay(uint8_t delay)
    {
        RTK_I2C_DELAY = delay;
    }

    int32_t reset()
    {
        int32_t retVal;
        retVal = rtl8367c_setAsicReg(RTL8367C_REG_CHIP_RESET, 1);
        if (retVal != RT_ERR_OK)
            return retVal;

        return RT_ERR_OK;
    }
};

#endif