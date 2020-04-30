#include<osal.h>
#defineUSER_TASK1_PRI 12
#defineUSER_TASK2_PRI 11
uint32_tuser_task1_id=0;
uint32_tuser_task2_id=0;

static int user_task1_entry()//任务1
{int n = 0;
    for(n = 0; n < 5; n++)
{
    printf("task1: my task id is %ld, n = %d!\r\n", user_task1_id, n);
    osal_task_sleep(2*1000);  
    }
printf("user task 1 exit!\r\n");
return 0;
}
static int user_task2_entry()//任务2
{
    while (1){
        printf("task 2: my task id is %ld!\r\n", user_task2_id);
        osal_task_sleep(2*1000);
    }
}

int standard_app_demo_main()
{
    user_task1_id = osal_task_create("user_task1",user_task1_entry,NULL,0x400,NULL,USER_TASK1_PRI);
    user_task2_id = osal_task_create("user_task2",user_task2_entry,NULL,0x400,NULL,USER_TASK2_PRI);
    return 0;
    }