/*
 * Bitmap.h
 *
 *  Created on: Jul 2, 2015
 *      Author: johnpurcell
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>		//for uint8_t
#include <memory>

namespace caveofprogramming {

class Bitmap {
private:
	int m_width{0};
	int m_height{0};
	std::unique_ptr<uint8_t[]> m_pPixels{nullptr};		//this enables us to not include a delete[] in the destructor of the class.

public:
	Bitmap(int width, int height);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	bool write(std::string filename);
	virtual ~Bitmap();
};

} /* namespace caveofprogramming */

#endif /* BITMAP_H_ */
