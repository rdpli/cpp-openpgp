// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNDecryptSignVerify.h"


@implementation PMNDecryptSignVerify

- (nonnull instancetype)initWithPlainText:(nonnull NSString *)plainText
                                   verify:(BOOL)verify
{
    if (self = [super init]) {
        _plainText = [plainText copy];
        _verify = verify;
    }
    return self;
}

+ (nonnull instancetype)decryptSignVerifyWithPlainText:(nonnull NSString *)plainText
                                                verify:(BOOL)verify
{
    return [[self alloc] initWithPlainText:plainText
                                    verify:verify];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p plainText:%@ verify:%@>", self.class, (void *)self, self.plainText, @(self.verify)];
}

@end
