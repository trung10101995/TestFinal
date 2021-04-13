//
//  VietIdSDKController.h
//  VietidSDK-iOS
//
//  Created by Le Minh Son on 11/13/18.
//  Copyright © 2018 songoku20. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KingAccessToken.h"
#import "KingIdException.h"
#import "KingUserInfo.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define VERSION_NAME @"0.5.5" // fix arr trả vè accessToken

#define EN @"en"
#define VI @"vi"
#define FR @"fr"

static NSInteger LOGIN = 0;//Show fullscreen of dialog authen
static NSInteger CHANGE_PASSWORD = 1; //Show fullscreen authen otherwise show web dialog to authen
static NSInteger LOGIN_APPPLE = 2;//login apple

@protocol OnKingIdResponse
-(void)onRequestSuccess:(KingUserInfo*)userInfo;
-(void)onRequestFailed:(KingIdException*) e;
@end

@protocol OnKingIdLoginCallback
-(void)onAuthenSuccess:(KingAccessToken*) accessToken;
-(void)onAuthenFailed:(KingIdException*) kingIdException;
-(void)onAuthenCancel;
-(void)onLoginApple;
//-(void)onLoginAppleWebView;
@end
@protocol OnListCurrentTokenCallback
-(void) onSuccess:(NSArray *)arr;
-(void) onFailed:(KingIdException *)ex;
@end


//For VietIdSDK public method and properties
@interface KingIdSDKController : NSObject

@property(nonatomic, strong) id<OnKingIdLoginCallback> onKingIdLoginCallback;
@property(nonatomic, strong) id<OnKingIdResponse> onKingIdResponseRequest;
@property(nonatomic, strong) id<OnListCurrentTokenCallback> onListCurrentTokenCallback;
@property(nonatomic) BOOL debugMode;
@property(nonatomic) BOOL disableExitLogin;
@property(nonatomic, strong) NSString* language;
@property(nonatomic) NSString *keychainService;
@property(nonatomic) NSString *keychainAccessGroup;
@property(nonatomic) BOOL enableAppleLogin;
//@property(nonatomic) int timeOutRequest;
/**
 * Create singleton instance of VietIdSDKController
 */
+(instancetype)sharedInstance;

/**
 * Init and make config for vietidController
 * Call first before working with VietIdController
 * Such that: [[VietIdSDKController sharedInstance] configure];
 */
-(void) configure:(NSString*) clientId clientSecret:(NSString*)clientSecret;

/**
 * @return clientId for your application with vietIdSDK
 */
-(NSString*)getCLientId;

/**
 * @return redirectUri for your application with vietIdSDK
 */
-(NSString*)getRedirectUri;

/**
 * @return clientSecret for your application with vietIdSDK
 */
-(NSString*)getClientSecret;

/**
 * @return bundleId of your application
 */
-(NSString*)getBundleId;

/**
 * Get identifier for device
 */

-(NSString*)getDeviceId;

/**
 * Get identifier for advertisers
 */
-(NSString*)getIDFA;

/**
 * Call to check logged in session on local
 *
 * @return boolean state true if token is valid otherwise
 */
-(BOOL)checkTokenOnLocal;

/**
 * Call to check logged in session with asynchronous from server check
 * Callback result via delegate class: OnVietIdResponse
 */
-(void)checkTokenOnServer;

//For login/logout
/**
 * Call this when you want to login via vietID
 */
-(void)login;
//For login/logout
/**
 * Call this when you want to login via vietID
 */
-(void)loginApple;
/**
 * Call this when you want to changePassword via vietID
 */
-(void)changePassword;

/**
 * Call this when you want to logout via vietID
 */
-(BOOL)logout;

/**
 * Call this when you want to logout via vietID with asynchronous state
 */
-(void)logoutAsync:(void(^)(BOOL  success,KingIdException* error))callback;

//For get user information
/**
 * Get user info with asynchronous
 */
-(void)getUserInfoAsync:(void(^)(BOOL success, KingIdException* _Nullable error, KingUserInfo* _Nullable userinfo))callback;
/**
 * Get user info with synchronous
 */
-(KingUserInfo*)getUserInfo;

/**
 * Set disable phone number on login session: YES if you want disable login via vietID with phonenumber otherwise
 */
-(void)disablePhone:(BOOL) disable;

/**
 * Get disable phone number on login session: YES if you want disable login via vietID with phonenumber otherwise
 */
-(NSString*)isDisablePhone;
/**
 * Get accounts login on device.
 */
-(void)getArrayAccounts:(void(^)(BOOL  success, NSArray<NSDictionary<NSString*,id>*> * _Nonnull devices, NSString* code))completion;

/**
 * Quick login with email or phone number.
 */
-(void)quickLogin:(NSString*)email code:(NSString*)code;

/**
 * Set cookies
 */
-(BOOL)importCookies API_AVAILABLE(ios(11));

/**
 *   export list cookie
 */
-(void) loginCookie;

@end

NS_ASSUME_NONNULL_END
