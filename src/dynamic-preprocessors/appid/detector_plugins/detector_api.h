/*
** Copyright (C) 2014 Cisco and/or its affiliates. All rights reserved.
** Copyright (C) 2005-2013 Sourcefire, Inc.
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License Version 2 as
** published by the Free Software Foundation.  You may not use, modify or
** distribute this program under any other version of the GNU General
** Public License.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef __DETECTOR_API_H__
#define __DETECTOR_API_H__

#include "client_app_api.h"
#include "service_api.h"
#include "client_app_base.h"
#include "service_base.h"

typedef void *(*DetectorFlowdataGet)(FLOW *, unsigned);
typedef int (*DetectorFlowdataAdd)(FLOW *, void *, unsigned, AppIdFreeFCN);

typedef struct _DETECTOR_API
{
    DetectorFlowdataGet data_get;
    DetectorFlowdataAdd data_add;
} DetectorApi;

/**compound detector with both service and client side.
 */
typedef struct _RNA_DETECTOR_VALIDATION_MODULE
{
    /**service side.*/
    RNAServiceValidationModule *service;

    /**client side.*/
    RNAClientAppModule *client;

    const DetectorApi *api;
    unsigned flow_data_index;
    StreamAPI *streamAPI;
} RNADetectorValidationModule;

#endif /*__DETECTOR_API_H__ */