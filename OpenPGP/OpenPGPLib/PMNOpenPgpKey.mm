// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNOpenPgpKey.h"


@implementation PMNOpenPgpKey

- (nonnull instancetype)initWithKeyId:(nonnull NSString *)keyId
                            publicKey:(nonnull NSString *)publicKey
                           privateKey:(nonnull NSString *)privateKey
                          fingerPrint:(nonnull NSString *)fingerPrint
                            isUpdated:(BOOL)isUpdated
{
    if (self = [super init]) {
        _keyId = [keyId copy];
        _publicKey = [publicKey copy];
        _privateKey = [privateKey copy];
        _fingerPrint = [fingerPrint copy];
        _isUpdated = isUpdated;
    }
    return self;
}

+ (nonnull instancetype)openPgpKeyWithKeyId:(nonnull NSString *)keyId
                                  publicKey:(nonnull NSString *)publicKey
                                 privateKey:(nonnull NSString *)privateKey
                                fingerPrint:(nonnull NSString *)fingerPrint
                                  isUpdated:(BOOL)isUpdated
{
    return [[self alloc] initWithKeyId:keyId
                             publicKey:publicKey
                            privateKey:privateKey
                           fingerPrint:fingerPrint
                             isUpdated:isUpdated];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p keyId:%@ publicKey:%@ privateKey:%@ fingerPrint:%@ isUpdated:%@>", self.class, (void *)self, self.keyId, self.publicKey, self.privateKey, self.fingerPrint, @(self.isUpdated)];
}

@end
