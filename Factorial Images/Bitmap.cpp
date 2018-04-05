/*
 * Bitmap.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: johnpurcell
 */

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace caveofprogramming;

namespace caveofprogramming {

	Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{})  {
	// TODO Auto-generated constructor stub

}

	bool Bitmap::write(std::string filename) {
		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height*3;
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.width=m_width;
		infoHeader.height=m_height;

		ofstream file;
		file.open(filename, ios::out|ios::binary );	//open a file in write binary mode

		if(!file){		//check if all is ok in opening the file. The ! is an overloaded operator.
			return false;
		}

		//writing to the file
		file.write((char*)&fileHeader, sizeof(fileHeader));	//needs a char* and an int. First we write the FILE header
		file.write((char*)&infoHeader, sizeof(infoHeader));	//needs a char* and an int. Then we write the INFO header
		file.write((char*)m_pPixels.get(), m_width*m_height*3);	//needs a char* and an int. Finally we write the actual data. In order to cast the unique pointer to a char* we need to call a method get() to the u pointer.


		file.close();
		if(!file){		//check if all is ok in closing the file. The ! is an overloaded operator.
			return false;
		}
	return false;
}

void Bitmap::setPixel( int x,  int y, uint8_t red, uint8_t green, uint8_t blue) {

	uint8_t* pPixel = m_pPixels.get();	//get returns a pointer to the underlying memory.

	pPixel += (y*3) * m_width + (x*3);
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;

}

Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace caveofprogramming */
