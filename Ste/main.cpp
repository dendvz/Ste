#include "stb_image_write.h"
#include "JpegImage.h"
#include "stegRGB.h"

int main(int argc, char* argv[])
{
    JpegImage jpegImage("C:\\Users\\Anna\\Desktop\\SN.jpg");

    if (jpegImage.m_pImageInfo)
    {
        RGB r(jpegImage.m_pImageInfo->nHeight, jpegImage.m_pImageInfo->nWidth, jpegImage.m_pImageInfo->nNumComponent);
        r.IntoRGB(jpegImage.m_pImageInfo->pData);

        r.FindBlockAndHideMessage("HelloWorld1", "First Secret message");
        r.FindBlockAndHideMessage("HelloWorld2", "First Secret message");
        r.FindBlockAndHideMessage("HelloWorld3", "First Secret message");
        r.FindBlockAndHideMessage("HelloWorld4", "First Secret message");

        r.OutRGB(jpegImage.m_pImageInfo->pData);
        //r.CalculateHistogram();
        stbi_write_jpg("C:\\Users\\Anna\\Desktop\\res.jpg", jpegImage.m_pImageInfo->nWidth, jpegImage.m_pImageInfo->nHeight, jpegImage.m_pImageInfo->nNumComponent, jpegImage.m_pImageInfo->pData, 100);
    }

    JpegImage jpegImage1("C:\\Users\\Anna\\Desktop\\res.jpg");
    if (jpegImage1.m_pImageInfo)
    {
        std::cout << "\nDif pic:\n";
        RGB r(jpegImage1.m_pImageInfo->nHeight, jpegImage1.m_pImageInfo->nWidth, jpegImage1.m_pImageInfo->nNumComponent);
        r.IntoRGB(jpegImage1.m_pImageInfo->pData);

        std::cout << r.FindBlockAndReturnMessage("HelloWorld1") << std::endl;
        std::cout << r.FindBlockAndReturnMessage("HelloWorld2") << std::endl;
        std::cout << r.FindBlockAndReturnMessage("HelloWorld3") << std::endl;
        std::cout << r.FindBlockAndReturnMessage("HelloWorld4") << std::endl;
    }
    return 0;
}
