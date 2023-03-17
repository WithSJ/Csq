#if !defined(CSQ_VM_4)
#define CSQ_VM_4
#include "../Parser/parser.h"
#include "../AST/ast.h"

enum TARGET_LANGUAGE{
    C,
    CPP
};

enum TARGET_COMPILER{
    CLANG,
    GCC,
    CLANGPP,
    GPP,
};

void CompileToGPP(string path, string name){
    string command = "g++ " + path + " -o " + name;
    system(command.c_str());
}

void CompileToClangPP(string path, string name){
    string command = "clang++ " + path + " -o " + name;
    system(command.c_str());
}

void CompileToGCC(string path, string name){
    string command = "gcc " + path + " -o " + name;
    system(command.c_str());
}

void CompileToClang(string path, string name){
    string command = "gcc " + path + " -o " + name;
    system(command.c_str());
}

void RunExecutable(string path){
    string command = path;
    system(command.c_str());
}

bool gcc,gpp,clang,clangpp;

void CompileToExec(string path, string name){
    if(gcc == 1){
        CompileToGCC(path, name);
    }
    else if(gpp == 1){
        CompileToGPP(path, name);
    }
    else if(clang == 1){
        CompileToClang(path, name);
    }
    else if(clangpp == 1){
        CompileToClangPP(path, name);
    }
}


#endif // CSQ_VM_4
