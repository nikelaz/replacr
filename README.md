# Replacr

A very simple windows string replacement utility. This was built primarily for educational/testing purposes.

## Build

This is a QT application. The recommended way to build it is to download QT Creator and use the IDE.
You can check out the official [QT documentation](https://doc.qt.io/qtcreator/creator-build-example-application.html) for more details.

## Package and Release a New Version

### 1. Copy DB template

Copy `presets-template.db` and `replacr.ico` to the build release directory

### 2. Add Dependencies after Building

QT and its core libraries are dynamically linked. They will not be included in the release/build folder after building with QT creator.

To do that before packaging the installer follow the [Deploying on Windows guide](https://doc.qt.io/qt-6/windows-deployment.html).

You essentially need to use the `QTDIR/bin/windeployqt.exe` or `QTDIR/bin/windeployqt6.exe` CLI tool. It has only one argument - the directory where you build executable can be found. It will analyze the executable and add all necessary runtime dependencies (dlls).

### 3. Create an Installer

The installer is created with the QT installer framework. All of the necessary configuration for Windows is prepared in the `/release` directory. To create a new release:

3.1. Copy the latest release build files (and dependencies) to the `/release/packages/com.nikelaz.replacr/data` directory.
3.2. Modify the `/release/packages/com.nikelaz.replacr/meta/package.xml` file with the new version and date of the release.

```xml
<Version>1.1</Version>
<ReleaseDate>2024-12-15</ReleaseDate>
```

3.3. Run the binarycreator.exe

```
Qt/Tools/QtInstallerFramework/<version>/bin/binarycreator.exe -c ./release/config/config.xml -p ./release/packages replacr_v1.1_amd64.exe
```

The current file name convention for the installer is:
```
<application-name>_v<version>_<arch>.exe
```

3.4. Create a new release in GitHub and attach the installer executable.