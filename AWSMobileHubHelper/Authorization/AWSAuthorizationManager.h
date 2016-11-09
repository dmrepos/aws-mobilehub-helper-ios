//
//  AWSAuthorizationManager.h
//
// Copyright 2016 Amazon.com, Inc. or its affiliates (Amazon). All Rights Reserved.
//
// Code generated by AWS Mobile Hub. Amazon gives unlimited permission to
// copy, distribute and modify it.
//

#import <Foundation/Foundation.h>
#import <SafariServices/SafariServices.h>
#import <UIKit/UIKit.h>

extern NSString *const AWSAuthorizationManagerErrorDomain;

typedef NS_ENUM(NSUInteger, AWSAuthorizationManagerError) {
    AWSAuthorizationErrorFailedToRetrieveAccessToken
};

@interface AWSAuthorizationManager : NSObject

/**
 * Singleton used to authorize user during OAuth1.0, 2.0, other flows.
 * @return the singleton
 */
+ (instancetype)sharedInstance;

/**
 * Utility method that constructs form encoded portion of url
 * i.e. @{@"grant": @"code", @"client_id": @"abc123"} -> @"grant=code&client_id=abc123"
 *
 * @return the string representation of a form
 */
+ (NSString *)constructURIWithParameters:(NSDictionary *)params;

/**
 * Utility method that constructs dictionary from simple form encoded url
 * i.e. @"grant=code&client_id=abc123" -> @{@"grant": @"code", @"client_id": @"abc123"}
 *
 * @return the dictionary representation of a url encoded form
 */
+ (NSMutableDictionary *)constructParametersWithURI:(NSString *)formString;

/**
 * Starts the authorization flow. Should be called from main thread.
 *
 * @param loginViewController The view controller that user sees right before they should see a login screen.
 * @param completionHandler The code that will follow after receiving successful login. Executes BEFORE login screen is dismissed.
 */
- (void)authorize:(UIViewController *)loginViewController completionHandler:(void (^)(id result, NSError *error)) completionHandler;

/**
 * Starts the refresh flow or possibly run the same authorize flow again.
 * Does not check if current accessToken is expired or not.
 *
 * @param refreshCompletionHandler The code that will follow after refreshing accessToken.
 */
- (void)refresh:(void (^)(id result, NSError *error))refreshCompletionHandler;

/**
 * This method should be placed in the AppDelegate to listen for the redirect URI.
 *
 * - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
 *
 * @param refreshCompletionHandler The code that will follow after refreshing accessToken.
 */
- (BOOL)handleURL:(NSURL *)url;

/**
 * @return the accessToken used for API calls
 */
- (NSString *)getAccessToken;

/**
 * Starts the logout flow. Should be called from main thread.
 *
 * @param logoutViewController The view controller that user sees right before they should see a logout indication.
 * @param completionHandler The code that will follow after receiving successful login. Executes BEFORE login screen is dismissed.
 */
- (void)logout:(UIViewController *)logoutViewController completionHandler:(void (^)(id result, NSError *error)) completionHandler;

@end