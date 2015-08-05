/*
 * Copyright 2010 Rockchip Electronics S.LSI Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include "os_env.h"

#define ENV_BUF_SIZE_LINUX  1024

RK_S32 os_get_env_u32(const char *name, RK_U32 *val)
{
    char *ptr = getenv(name);
    *val = (RK_U32)atoi(ptr);
    return 0;
}

RK_S32 os_get_env_str(const char *name, char **val)
{
    *val = getenv(name);
    return (*val)?(0):(-1);
}

RK_S32 os_set_env_u32(const char *name, RK_U32 val)
{
    char buf[ENV_BUF_SIZE_LINUX];
    snprintf(buf, sizeof(buf), "%u", val);
    return setenv(name, buf, 1);
}

RK_S32 os_set_env_str(const char *name, char *val)
{
    return setenv(name, val, 1);
}


