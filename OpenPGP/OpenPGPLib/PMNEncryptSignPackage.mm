// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNEncryptSignPackage.h"


@implementation PMNEncryptSignPackage

- (nonnull instancetype)initWithEncrypted:(nonnull NSString *)encrypted
                                signature:(nonnull NSString *)signature
{
    if (self = [super init]) {
        _encrypted = [encrypted copy];
        _signature = [signature copy];
    }
    return self;
}

+ (nonnull instancetype)encryptSignPackageWithEncrypted:(nonnull NSString *)encrypted
                                              signature:(nonnull NSString *)signature
{
    return [[self alloc] initWithEncrypted:encrypted
                                 signature:signature];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p encrypted:%@ signature:%@>", self.class, (void *)self, self.encrypted, self.signature];
}

@end