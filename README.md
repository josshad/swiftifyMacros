# swiftifyMacros

Syntax sugar macros for objective c to use some swift features. These macros will save a lot of time while developing

##Features

- `let` and `var` for auto type variables
- `_` for unused variables
- force_unwrap for nonnil variables
- self cast
- Clamp

## Installation

### Manual

Drop `SwiftifyMacros.h` in your project. (Or copy content of this file to your macros file).
Add `#include SwiftifyMacros.h` in precompile prefix header file.

## Usage

### Auto types

Use let for constant variables:

	- (UIView *)foo {
		let a = CGRectMake(0, 0, 10, 10);
		let someView = [UIView new];
		someView.frame = a;
		return someView;
	}

Use var for mutable variables:
	- (UIView *)bar {
		var a = CGRectMake(0, 0, 10, 10);
		a.origin.x = 10;
		let someView = [UIView new];
		someView.frame = a;
		return someView;
	}

### Unused
To avoid "unused parameter warnings". Instead of using `__unused` word for unused variables in methods and blocks you can simply write `_`. Like in swift

Block example:

    [[NetHelper sharedInstance] postRequestWithURLString:URL 
    												data:data 
    										 withSuccess:^(id _) {
            										NSLog(@"Succes");
        									   } failure:^(NSError *_) {
        											NSLog(@"Failure");
    }];

Method example:

	- (NSInteger)collectionView:(UICollectionView *)_ numberOfItemsInSection:(NSInteger)_ {
    	return 0;
	}

### Force unwrap
To avoid warning of using nullable variables in nonull arguments

	- (void)foo:(nullable UICollectionViewLayout *)layout {
		if (layout) {
			let collectionView = [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:force_unwrap(layout)];
			...
		} else {
			...
		}
	}

### Self cast
	
	- (BOOL)isEqual:(id)object {
    	if (object == nil || ![object isKindOfClass:self.class])
        	return NO;
    
    	let other = self_cast(object);
    	return [self.guid isEqual:other.guid];
	}

### Clamp
Instead of using MIN(max, MAX(value, min)) you can use clamp:

	- (NSInteger)foo {
		let a = arc4random()%100;
		let b = CLAMP(a, 10, 90); //b in [10, 90]
		return b;
	}