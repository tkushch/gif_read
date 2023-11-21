#include <iomanip>
#include <iostream>
#include <string>

#include "EasyGifReader/EasyGifReader.h"

std::uint32_t clear_alpha(std::uint32_t x) { return x & 0x00FFFFFF; }

void mygif(std::string path) {
    try {
        EasyGifReader gifReader = EasyGifReader::openFile(path.data());
        int frameCount = gifReader.frameCount();
        int width = gifReader.width();
        int height = gifReader.height();
        std::cout << "width " << width << std::endl;
        std::cout << "height " << height << std::endl;
        bool loop = gifReader.repeatInfinitely();
        std::cout << "number of frames: " << frameCount << std::endl;
        for (const EasyGifReader::Frame &frame : gifReader) {
            const std::uint32_t *framePixels =
                frame.pixels();  // массив длины width * height с ARGB пикселями - 8 битными числами
            auto pixel_example = clear_alpha(framePixels[0]);  // ARGB -> RGB
            std::cout << "pixel example: " << std::setfill('0') << std::setw(6) << std::hex << pixel_example
                      << std::endl;
            // double frameDuration = frame.duration().seconds();
        }
    } catch (EasyGifReader::Error gifError) {
        std::cerr << "Reading GIF file failed" << std::endl;
    }
}

int main() {
    std::string path;
    // std::cin >> path;
    path = "sample1.gif";
    // path = "sample1.gif";
    mygif(path);
    return 0;
}