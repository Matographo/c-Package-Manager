#ifndef CPPP_H
#define CPPP_H

#include <filesystem>
#include <iostream>
#include "Downloader.h"
#include "sqlite3.h"
#include "PackageManager.h"

class CProg : public PackageManager {
private:
    PackageManagerToolkit * toolkit;
    const std::string progLang = "c";
    const std::string gitRepo = "Matographo/c-database";
    

    int createNewVersion(Package * pkg, PackagePaths * pkgPath);

public:
    CProg();
    virtual ~CProg();
    
    virtual int install(std::string package) override;
    virtual int install(std::vector<std::string> packages) override;
    virtual int uninstall(std::string package) override;
    virtual int uninstall(std::vector<std::string> packages) override;
    virtual int update(std::string package) override;
    virtual int update(std::vector<std::string> packages) override;
    virtual int update() override;
    virtual int search(std::string package) override;
    virtual int list() override;
    virtual int info(std::string package) override;
    virtual void setToolkit(PackageManagerToolkit * toolkit) override;
};

#endif