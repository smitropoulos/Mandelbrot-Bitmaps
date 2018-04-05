	//
	//  main.cpp
	//  Factorial Images
	//
	//  Created by Stefanos Mitropoulos on 05/04/2018.
	//  Copyright © 2018 Stefanos Mitropoulos. All rights reserved.
	//

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(push,2)		//remove padding

namespace caveofprogramming {

	struct BitmapFileHeader {
		char header[2] { 'B', 'M' };
		int32_t fileSize;		//The size of the file
		int32_t reserved { 0 };
		int32_t dataOffset;		//The distance (in bytes) between the start of the file and the start of the data
	};

}

#endif /* BITMAPFILEHEADER_H_ */
