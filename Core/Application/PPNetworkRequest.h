//
//  PPNetworkRequest.h
//  groupbuy
//
//  Created by qqn_pipi on 11-7-23.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#define NETWORK_TIMEOUT 30      // 30 seconds for time out

enum {
    
    ERROR_SUCCESS                   = 0,
    
	ERROR_NETWORK                   = 99901,
    
    ERROR_CLIENT_URL_NULL           = 190001,
    ERROR_CLIENT_REQUEST_NULL       = 190002,
    ERROR_CLIENT_PARSE_JSON         = 190003,
    ERROR_CLIENT_PARSE_DATA         = 190004

};

@interface CommonNetworkOutput : NSObject
{
	int             resultCode;
	NSString*       resultMessage;
    
    NSArray*        jsonDataArray;
    NSDictionary*   jsonDataDict;
    NSString*       textData;
    NSData*         responseData;
}

@property (nonatomic, assign) int			resultCode;
@property (nonatomic, retain) NSString*		resultMessage;
@property (nonatomic, retain) NSArray*        jsonDataArray;
@property (nonatomic, retain) NSDictionary*   jsonDataDict;

// for football project
@property (nonatomic, retain) NSString*       textData;
@property (nonatomic, retain) NSArray*        arrayData;

@property (nonatomic, retain) NSData*         responseData;

- (void)resultFromJSON:(NSString*)jsonString;
- (NSDictionary*)dictionaryDataFromJSON:(NSString*)jsonString;
- (NSArray*)arrayFromJSON:(NSString*)jsonString;

@end


typedef void (^ConstructHTTPRequestBlock)();
typedef NSString* (^ConstructURLBlock)(NSString* baseURL);
typedef void (^PPNetworkResponseBlock)(NSDictionary* dict, CommonNetworkOutput* output);

@interface PPNetworkRequest : NSObject {
    
}

+ (CommonNetworkOutput*)uploadRequest:(NSString *)baseURL 
                           uploadData:(NSData*)uploadData
                  constructURLHandler:(ConstructURLBlock)constructURLHandler 
                      responseHandler:(PPNetworkResponseBlock)responseHandler 
                               output:(CommonNetworkOutput *)output;

+ (CommonNetworkOutput*)uploadRequest:(NSString *)baseURL
                        imageDataDict:(NSDictionary *)imageDataDict
                         postDataDict:(NSDictionary *)postDataDict
                  constructURLHandler:(ConstructURLBlock)constructURLHandler 
                      responseHandler:(PPNetworkResponseBlock)responseHandler 
                               output:(CommonNetworkOutput *)output;

+ (CommonNetworkOutput*)sendRequest:(NSString*)baseURL
         constructURLHandler:(ConstructURLBlock)constructURLHandler
             responseHandler:(PPNetworkResponseBlock)responseHandler
                      output:(CommonNetworkOutput*)output;

+ (CommonNetworkOutput*)sendRequest:(NSString*)baseURL
                constructURLHandler:(ConstructURLBlock)constructURLHandler
                    responseHandler:(PPNetworkResponseBlock)responseHandler
                       outputFormat:(int)outputFormat
                             output:(CommonNetworkOutput*)output;

+ (CommonNetworkOutput*)sendPostRequest:(NSString*)baseURL
                                   data:(NSData*)data
                    constructURLHandler:(ConstructURLBlock)constructURLHandler
                        responseHandler:(PPNetworkResponseBlock)responseHandler
                           outputFormat:(int)outputFormat
                                 output:(CommonNetworkOutput*)output;

+ (NSString*)appendTimeStampAndMacToURL:(NSString*)url shareKey:(NSString*)shareKey;

@end

