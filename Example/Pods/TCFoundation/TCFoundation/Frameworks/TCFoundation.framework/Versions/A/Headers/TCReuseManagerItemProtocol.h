//
//  TCReuseManagerItemProtocol.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#import <Foundation/Foundation.h>

@protocol TCReuseManagerItemProtocol <NSObject>
-(void)onPrepareForReuse:(id)sender;
@end
