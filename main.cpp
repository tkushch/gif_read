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
        for (const EasyGifReader::Frame &frame : gifReader) {
            const std::uint32_t *framePixels =
                frame.pixels();  // массив длины width * height с пикселями -
                                 // 8 битными числами, первые два бита - яркость, далее - RGB
            std::cout << std::hex << framePixels[0] << " ";
            std::cout << std::hex << clear_alpha(framePixels[0]) << std::endl;

            double frameDuration = frame.duration().seconds();
        }
    } catch (EasyGifReader::Error gifError) {
        std::cerr << "Reading GIF file failed" << std::endl;
    }
}

int main() {
    std::string path;
    // std::cin >> path;
    path = "sample.gif";
    // path = "sample1.gif";
    mygif(path);
    return 0;
}