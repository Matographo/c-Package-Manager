#ifndef PACKAGE_MANAGER_TOOLKIT_H
#define PACKAGE_MANAGER_TOOLKIT_H

#include <string>


// Structs for package information
struct Package {
    std::string name;
    std::string version;
    bool isHash;
};

// Struct for package paths
struct PackagePaths {
    std::string homePath;
    std::string databaseBasePath;
    std::string databasePath;
    std::string languagePackagePath;
    std::string packageBasePath;
    std::string packageVersionPath;
    std::string packageRawPath;
};

/**
 * Toolkit for package managers to use for common tasks
 */
class PackageManagerToolkit {
public:

    virtual ~PackageManagerToolkit() = default;
    
    
    virtual Package parsePackage(std::string parsePackage) = 0;
    virtual PackagePaths getPackagePaths(std::string packageLanguage, std::string packageName, std::string version) = 0;
    virtual int installOwnDatabase(std::string packageLanguage, std::string gitRepo) = 0;
    virtual std::string getRepoFromDatabase(std::string packageLanguage, std::string packageName) = 0;
    virtual int installInSys(std::string tool) = 0;
    virtual int listInstalledPackages(std::string packageLanguage) = 0;
    virtual int searchPackageDatabase(std::string packageLanguage, std::string search) = 0;
    virtual int updatePackage(std::string packageLanguage, std::string packageName) = 0;
    virtual int updateAllPackages(std::string packageLanguage) = 0;
    virtual int uninstallPackage(std::string packageLanguage, std::string packageName, std::string version) = 0; 
    virtual int uinistallAllPackages(std::string packageLanguage) = 0;
    virtual int infoPackage(std::string packageLanguage, std::string packageName) = 0;
    
    virtual void setPackagePaths(PackagePaths paths) = 0;

};

#endif // PACKAGE_MANAGER_TOOLKIT_H