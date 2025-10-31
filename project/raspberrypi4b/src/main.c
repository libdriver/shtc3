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
 * @file      main.c
 * @brief     main source file
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

#include "driver_shtc3_register_test.h"
#include "driver_shtc3_read_test.h"
#include "driver_shtc3_basic.h"
#include <getopt.h>
#include <stdlib.h>

/**
 * @brief     shtc3 full function
 * @param[in] argc arg numbers
 * @param[in] **argv arg address
 * @return    status code
 *            - 0 success
 *            - 1 run failed
 *            - 5 param is invalid
 * @note      none
 */
uint8_t shtc3(uint8_t argc, char **argv)
{
    int c;
    int longindex = 0;
    const char short_options[] = "hipe:t:";
    const struct option long_options[] =
    {
        {"help", no_argument, NULL, 'h'},
        {"information", no_argument, NULL, 'i'},
        {"port", no_argument, NULL, 'p'},
        {"example", required_argument, NULL, 'e'},
        {"test", required_argument, NULL, 't'},
        {"times", required_argument, NULL, 1},
        {NULL, 0, NULL, 0},
    };
    char type[33] = "unknown";
    uint32_t times = 3;
    
    /* if no params */
    if (argc == 1)
    {
        /* goto the help */
        goto help;
    }
    
    /* init 0 */
    optind = 0;
    
    /* parse */
    do
    {
        /* parse the args */
        c = getopt_long(argc, argv, short_options, long_options, &longindex);
        
        /* judge the result */
        switch (c)
        {
            /* help */
            case 'h' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "h");
                
                break;
            }
            
            /* information */
            case 'i' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "i");
                
                break;
            }
            
            /* port */
            case 'p' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "p");
                
                break;
            }
            
            /* example */
            case 'e' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "e_%s", optarg);
                
                break;
            }
            
            /* test */
            case 't' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "t_%s", optarg);
                
                break;
            }
            
            /* running times */
            case 1 :
            {
                /* set the times */
                times = atol(optarg);
                
                break;
            } 
            
            /* the end */
            case -1 :
            {
                break;
            }
            
            /* others */
            default :
            {
                return 5;
            }
        }
    } while (c != -1);

    /* run the function */
    if (strcmp("t_reg", type) == 0)
    {
        /* run reg test */
        if (shtc3_register_test() != 0)
        {
            return 1;
        }
        
        return 0;
    }
    else if (strcmp("t_read", type) == 0)
    {
        /* run read test */
        if (shtc3_read_test(times) != 0)
        {
            return 1;
        }
        
        return 0;
    }
    else if (strcmp("e_read", type) == 0)
    {
        uint8_t res;
        uint32_t i;
        float temperature;
        float humidity;
        
        /* basic init */
        res = shtc3_basic_init();
        if (res != 0)
        {
            return 1;
        }
        
        /* loop */
        for (i = 0; i < times; i++)
        {
            /* delay 1000ms */
            shtc3_interface_delay_ms(1000);
            
            /* read data */
            res = shtc3_basic_read((float *)&temperature, (float *)&humidity);
            if (res != 0)
            {
                (void)shtc3_basic_deinit();
                
                return 1;
            }
            
            /* output */
            shtc3_interface_debug_print("shtc3: %d/%d.\n", (uint32_t)(i + 1), (uint32_t)times);
            shtc3_interface_debug_print("shtc3: temperature is %0.2fC.\n", temperature);
            shtc3_interface_debug_print("shtc3: humidity is %0.2f%%.\n", humidity);
        }
        
        /* basic deinit */
        (void)shtc3_basic_deinit();
        
        return 0;
    }
    else if (strcmp("e_read-lp", type) == 0)
    {
        uint8_t res;
        uint32_t i;
        float temperature;
        float humidity;
        
        /* basic init */
        res = shtc3_basic_init();
        if (res != 0)
        {
            return 1;
        }
        
        /* loop */
        for (i = 0; i < times; i++)
        {
            /* delay 1000ms */
            shtc3_interface_delay_ms(1000);
            
            /* read data */
            res = shtc3_basic_read_low_power((float *)&temperature, (float *)&humidity);
            if (res != 0)
            {
                (void)shtc3_basic_deinit();
                
                return 1;
            }
            
            /* output */
            shtc3_interface_debug_print("shtc3: %d/%d.\n", (uint32_t)(i + 1), (uint32_t)times);
            shtc3_interface_debug_print("shtc3: temperature is %0.2fC.\n", temperature);
            shtc3_interface_debug_print("shtc3: humidity is %0.2f%%.\n", humidity);
        }
        
        /* basic deinit */
        (void)shtc3_basic_deinit();
        
        return 0;
    }
    else if (strcmp("e_reset", type) == 0)
    {
        uint8_t res;
        
        /* basic init */
        res = shtc3_basic_init();
        if (res != 0)
        {
            return 1;
        }
        
        /* soft reset */
        res = shtc3_basic_soft_reset();
        if (res != 0)
        {
            (void)shtc3_basic_deinit();
            
            return 1;
        }
        
        shtc3_interface_debug_print("shtc3: soft reset.\n");
        
        /* basic deinit */
        (void)shtc3_basic_deinit();
        
        return 0;
    }
    else if (strcmp("e_sleep", type) == 0)
    {
        uint8_t res;
        
        /* basic init */
        res = shtc3_basic_init();
        if (res != 0)
        {
            return 1;
        }
        
        /* sleep */
        res = shtc3_basic_sleep();
        if (res != 0)
        {
            (void)shtc3_basic_deinit();
            
            return 1;
        }
        
        shtc3_interface_debug_print("shtc3: sleep.\n");
        
        /* basic deinit */
        (void)shtc3_basic_wakeup();
        (void)shtc3_basic_deinit();
        
        return 0;
    }
    else if (strcmp("e_wakeup", type) == 0)
    {
        uint8_t res;
        
        /* basic init */
        res = shtc3_basic_init();
        if (res != 0)
        {
            return 1;
        }
        
        /* wakeup */
        res = shtc3_basic_wakeup();
        if (res != 0)
        {
            (void)shtc3_basic_deinit();
            
            return 1;
        }
        
        shtc3_interface_debug_print("shtc3: wakeup.\n");
        
        /* basic deinit */
        (void)shtc3_basic_deinit();
        
        return 0;
    }
    else if (strcmp("h", type) == 0)
    {
        help:
        shtc3_interface_debug_print("Usage:\n");
        shtc3_interface_debug_print("  shtc3 (-i | --information)\n");
        shtc3_interface_debug_print("  shtc3 (-h | --help)\n");
        shtc3_interface_debug_print("  shtc3 (-p | --port)\n");
        shtc3_interface_debug_print("  shtc3 (-t reg | --test=reg)\n");
        shtc3_interface_debug_print("  shtc3 (-t read | --test=read) [--times=<num>]\n");
        shtc3_interface_debug_print("  shtc3 (-e read | --example=read) [--times=<num>]\n");
        shtc3_interface_debug_print("  shtc3 (-e read-lp | --example=read-lp) [--times=<num>]\n");
        shtc3_interface_debug_print("  shtc3 (-e reset | --example=reset)\n");
        shtc3_interface_debug_print("  shtc3 (-e sleep | --example=sleep)\n");
        shtc3_interface_debug_print("  shtc3 (-e wakeup | --example=wakeup)\n");
        shtc3_interface_debug_print("\n");
        shtc3_interface_debug_print("Options:\n");
        shtc3_interface_debug_print("  -e <read | read-lp | reset | sleep | wakeup>, --example=<read | read-lp | reset | sleep | wakeup>\n");
        shtc3_interface_debug_print("                        Run the driver example.\n");
        shtc3_interface_debug_print("  -h, --help            Show the help.\n");
        shtc3_interface_debug_print("  -i, --information     Show the chip information.\n");
        shtc3_interface_debug_print("  -p, --port            Display the pin connections of the current board.\n");
        shtc3_interface_debug_print("  -t <reg | read>, --test=<reg | read>\n");
        shtc3_interface_debug_print("                        Run the driver test.\n");
        shtc3_interface_debug_print("      --times=<num>     Set the running times.([default: 3])\n");
        
        return 0;
    }
    else if (strcmp("i", type) == 0)
    {
        shtc3_info_t info;
        
        /* print shtc3 info */
        shtc3_info(&info);
        shtc3_interface_debug_print("shtc3: chip is %s.\n", info.chip_name);
        shtc3_interface_debug_print("shtc3: manufacturer is %s.\n", info.manufacturer_name);
        shtc3_interface_debug_print("shtc3: interface is %s.\n", info.interface);
        shtc3_interface_debug_print("shtc3: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        shtc3_interface_debug_print("shtc3: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        shtc3_interface_debug_print("shtc3: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        shtc3_interface_debug_print("shtc3: max current is %0.2fmA.\n", info.max_current_ma);
        shtc3_interface_debug_print("shtc3: max temperature is %0.1fC.\n", info.temperature_max);
        shtc3_interface_debug_print("shtc3: min temperature is %0.1fC.\n", info.temperature_min);
        
        return 0;
    }
    else if (strcmp("p", type) == 0)
    {
        /* print pin connection */
        shtc3_interface_debug_print("shtc3: SCL connected to GPIO3(BCM).\n");
        shtc3_interface_debug_print("shtc3: SDA connected to GPIO2(BCM).\n");
        
        return 0;
    }
    else
    {
        return 5;
    }
}

/**
 * @brief     main function
 * @param[in] argc arg numbers
 * @param[in] **argv arg address
 * @return    status code
 *             - 0 success
 * @note      none
 */
int main(uint8_t argc, char **argv)
{
    uint8_t res;

    res = shtc3(argc, argv);
    if (res == 0)
    {
        /* run success */
    }
    else if (res == 1)
    {
        shtc3_interface_debug_print("shtc3: run failed.\n");
    }
    else if (res == 5)
    {
        shtc3_interface_debug_print("shtc3: param is invalid.\n");
    }
    else
    {
        shtc3_interface_debug_print("shtc3: unknown status code.\n");
    }

    return 0;
}
