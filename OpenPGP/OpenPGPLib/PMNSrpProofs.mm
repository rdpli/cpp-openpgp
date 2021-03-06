// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNSrpProofs.h"


@implementation PMNSrpProofs

- (nonnull instancetype)initWithClientEphemeral:(nonnull NSData *)clientEphemeral
                                    clientProof:(nonnull NSData *)clientProof
                            expectedServerProof:(nonnull NSData *)expectedServerProof
{
    if (self = [super init]) {
        _clientEphemeral = [clientEphemeral copy];
        _clientProof = [clientProof copy];
        _expectedServerProof = [expectedServerProof copy];
    }
    return self;
}

+ (nonnull instancetype)srpProofsWithClientEphemeral:(nonnull NSData *)clientEphemeral
                                         clientProof:(nonnull NSData *)clientProof
                                 expectedServerProof:(nonnull NSData *)expectedServerProof
{
    return [[self alloc] initWithClientEphemeral:clientEphemeral
                                     clientProof:clientProof
                             expectedServerProof:expectedServerProof];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p clientEphemeral:%@ clientProof:%@ expectedServerProof:%@>", self.class, (void *)self, self.clientEphemeral, self.clientProof, self.expectedServerProof];
}

@end
