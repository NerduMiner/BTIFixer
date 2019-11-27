#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    if (argc==2)
    {
        //Create a binary fstream that opens a bti out of the command line argument
        std::fstream fout(argv[argc-1], std::ios::binary | std::ios::in | std::ios::out);
        //Jump to 0x6 in the file to begin editing the texture wrap mode
        if (fout.open())
        {
            std::cout<<"Opening "<<argv[argc-1]<<std::endl;
            fout.seekp(6);
            //Use int16 = 0 to change 2 bytes;
            int16_t t=0;
            //Write new mode to file by converting the int16 t into a char pointer and then using a size of 2 bytes
            fout.write(reinterpret_cast<char*>(&t),sizeof(int16_t));
            std::cout<<"Finished changing wrapping mode";
            //Finish up the changes and close
            fout.flush();
            fout.close();
        }
    }else{
        std::cout<<"Changes the wrapping mode on a .bti file so it works with console\nUSAGE: BTIFixer [f]\n[f]=.bti file";
    }
}
