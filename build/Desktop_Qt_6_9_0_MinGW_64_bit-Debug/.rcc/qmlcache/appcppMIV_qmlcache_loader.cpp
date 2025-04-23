#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _qt_qml_cppMIV_Main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_cppMIV_BotaoMudarPagina_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_cppMIV_HomePage_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_cppMIV_ReportPage_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_cppMIV_ReadingPage_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_cppMIV_DownloadPage_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_cppMIV_CommandPage_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_cppMIV_AnalysisPage_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_cppMIV_functions_js { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_cppMIV_ListaSinais_js { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/cppMIV/Main.qml"), &QmlCacheGeneratedCode::_qt_qml_cppMIV_Main_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/cppMIV/BotaoMudarPagina.qml"), &QmlCacheGeneratedCode::_qt_qml_cppMIV_BotaoMudarPagina_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/cppMIV/HomePage.qml"), &QmlCacheGeneratedCode::_qt_qml_cppMIV_HomePage_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/cppMIV/ReportPage.qml"), &QmlCacheGeneratedCode::_qt_qml_cppMIV_ReportPage_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/cppMIV/ReadingPage.qml"), &QmlCacheGeneratedCode::_qt_qml_cppMIV_ReadingPage_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/cppMIV/DownloadPage.qml"), &QmlCacheGeneratedCode::_qt_qml_cppMIV_DownloadPage_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/cppMIV/CommandPage.qml"), &QmlCacheGeneratedCode::_qt_qml_cppMIV_CommandPage_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/cppMIV/AnalysisPage.qml"), &QmlCacheGeneratedCode::_qt_qml_cppMIV_AnalysisPage_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/cppMIV/functions.js"), &QmlCacheGeneratedCode::_qt_qml_cppMIV_functions_js::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/cppMIV/ListaSinais.js"), &QmlCacheGeneratedCode::_qt_qml_cppMIV_ListaSinais_js::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appcppMIV)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appcppMIV))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_appcppMIV)() {
    return 1;
}
