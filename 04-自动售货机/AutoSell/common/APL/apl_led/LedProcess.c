/*********************************************************************************************
* 文件：
* 作者：
* 说明：
* 功能：
* 修改：
*********************************************************************************************/
/*********************************************************************************************
* 头文件
*********************************************************************************************/
#include "LedProcess.h"
#include "fml_led/fml_led.h"

PROCESS(LedProcess, "LedProcess");

/*********************************************************************************************
* 名称：PROCESS_THREAD(LedProcess, ev, data)
* 功能：LED处理进程
* 参数：LedProcess, ev, data
* 返回：无
* 修改：无
*********************************************************************************************/
PROCESS_THREAD(LedProcess, ev, data)
{
  PROCESS_BEGIN();
  
  static struct etimer et_Led;
  
  Bsp_LedInit();
  
  while (1)
  {
    Bsp_LedTurn(4);
    etimer_set(&et_Led,1000);
    PROCESS_WAIT_EVENT_UNTIL(ev==PROCESS_EVENT_TIMER);  
  }
  
  PROCESS_END();
}

