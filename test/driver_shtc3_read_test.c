/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_shtc3_read_test.c
 * @brief     driver shtc3 read test source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2025-11-03
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2025/11/03  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_shtc3_read_test.h"

static shtc3_handle_t gs_handle;        /**< shtc3 handle */

/**
 * @brief     read test
 * @param[in] times test times
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t shtc3_read_test(uint32_t times)
{
    uint8_t res;
    uint32_t i;
    shtc3_info_t info;
    
    /* link functions */
    DRIVER_SHTC3_LINK_INIT(&gs_handle, shtc3_handle_t);
    DRIVER_SHTC3_LINK_IIC_INIT(&gs_handle, shtc3_interface_iic_init);
    DRIVER_SHTC3_LINK_IIC_DEINIT(&gs_handle, shtc3_interface_iic_deinit);
    DRIVER_SHTC3_LINK_IIC_READ_ADDRESS16(&gs_handle, shtc3_interface_iic_read_address16);
    DRIVER_SHTC3_LINK_IIC_WRITE_ADDRESS16(&gs_handle, shtc3_interface_iic_write_address16);
    DRIVER_SHTC3_LINK_DELAY_MS(&gs_handle, shtc3_interface_delay_ms);
    DRIVER_SHTC3_LINK_DEBUG_PRINT(&gs_handle, shtc3_interface_debug_print);
    
    /* shtc3 info */
    res = shtc3_info(&info);
    if (res != 0)
    {
        shtc3_interface_debug_print("shtc3: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print chip information */
        shtc3_interface_debug_print("shtc3: chip is %s.\n", info.chip_name);
        shtc3_interface_debug_print("shtc3: manufacturer is %s.\n", info.manufacturer_name);
        shtc3_interface_debug_print("shtc3: interface is %s.\n", info.interface);
        shtc3_interface_debug_print("shtc3: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        shtc3_interface_debug_print("shtc3: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        shtc3_interface_debug_print("shtc3: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        shtc3_interface_debug_print("shtc3: max current is %0.2fmA.\n", info.max_current_ma);
        shtc3_interface_debug_print("shtc3: max temperature is %0.1fC.\n", info.temperature_max);
        shtc3_interface_debug_print("shtc3: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* start read test */
    shtc3_interface_debug_print("shtc3: start read test.\n");
    
    /* shtc3 init */
    res = shtc3_init(&gs_handle);
    if (res != 0)
    {
        shtc3_interface_debug_print("shtc3: init failed.\n");
       
        return 1;
    }
    
    /* enable clock stretching */
    shtc3_interface_debug_print("shtc3: enable clock stretching.\n");
    
    /* normal read test */
    shtc3_interface_debug_print("shtc3: normal read test.\n");
    
    /* wait 10 ms */
    shtc3_interface_delay_ms(10);
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        res = shtc3_read(&gs_handle, SHTC3_BOOL_TRUE, (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            shtc3_interface_debug_print("shtc3: read failed.\n");
            (void)shtc3_deinit(&gs_handle);
            
            return 1;
        }
        shtc3_interface_debug_print("shtc3: temperature is %0.2fC.\n", temperature_s);
        shtc3_interface_debug_print("shtc3: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 2500 ms */
        shtc3_interface_delay_ms(2500);
    }
    
    /* low power read test */
    shtc3_interface_debug_print("shtc3: low power read test.\n");
    
    /* wait 10 ms */
    shtc3_interface_delay_ms(10);
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        res = shtc3_read_low_power(&gs_handle, SHTC3_BOOL_TRUE, (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            shtc3_interface_debug_print("shtc3: read low power failed.\n");
            (void)shtc3_deinit(&gs_handle);
            
            return 1;
        }
        shtc3_interface_debug_print("shtc3: temperature is %0.2fC.\n", temperature_s);
        shtc3_interface_debug_print("shtc3: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 2500 ms */
        shtc3_interface_delay_ms(2500);
    }
    
#ifndef SHTC3_DISABLE_NO_CLOCK_STRETCHING_TEST
    /* disable clock stretching */
    shtc3_interface_debug_print("shtc3: disable clock stretching.\n");
    
    /* link functions */
    DRIVER_SHTC3_LINK_IIC_READ_ADDRESS16(&gs_handle, shtc3_interface_iic_scl_read_address16);
    
    /* normal read test */
    shtc3_interface_debug_print("shtc3: normal read test.\n");
    
    /* wait 10 ms */
    shtc3_interface_delay_ms(10);
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        res = shtc3_read(&gs_handle, SHTC3_BOOL_FALSE, (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            shtc3_interface_debug_print("shtc3: read failed.\n");
            (void)shtc3_deinit(&gs_handle);
            
            return 1;
        }
        shtc3_interface_debug_print("shtc3: temperature is %0.2fC.\n", temperature_s);
        shtc3_interface_debug_print("shtc3: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 2500 ms */
        shtc3_interface_delay_ms(2500);
    }
    
    /* low power read test */
    shtc3_interface_debug_print("shtc3: low power read test.\n");
    
    /* wait 10 ms */
    shtc3_interface_delay_ms(10);
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        res = shtc3_read_low_power(&gs_handle, SHTC3_BOOL_FALSE, (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            shtc3_interface_debug_print("shtc3: read low power failed.\n");
            (void)shtc3_deinit(&gs_handle);
            
            return 1;
        }
        shtc3_interface_debug_print("shtc3: temperature is %0.2fC.\n", temperature_s);
        shtc3_interface_debug_print("shtc3: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 2500 ms */
        shtc3_interface_delay_ms(2500);
    }
#endif
    
    /* finish read test */
    shtc3_interface_debug_print("shtc3: finish read test.\n");
    (void)shtc3_deinit(&gs_handle);

    return 0;
}
