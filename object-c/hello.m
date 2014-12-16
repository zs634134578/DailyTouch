#import <stdio.h>
#import <Foundation/Foundation.h>

int main(int argc, const char *argv[]) {
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    NSString *aa = @"Hello world!";
    NSLog(@"Hello world\n");
    printf("Length of aa is: %i\n",[aa length]);
    [pool drain];
    return 0;
}
