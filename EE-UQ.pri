
#message($$_PRO_FILE_PWD_)
#message($$PWD)

INCLUDEPATH += $$PWD \
    $$PWD/StochasticMotionInput/include

INCLUDEPATH += "../EE-UQ"

SOURCES += \
    $$PWD/UniformMotionInput.cpp \
    $$PWD/EarthquakeEventSelection.cpp \
    $$PWD/ExistingPEER_Events.cpp \
    $$PWD/SHAMotionWidget.cpp \
    $$PWD/EDP_Selection.cpp \
    $$PWD/EarthquakeRecord.cpp \
    $$PWD/StandardEarthquakeEDP.cpp \
    $$PWD/StochasticMotionInput/src/StochasticMotionInputWidget.cpp \
    $$PWD/StochasticMotionInput/src/StochasticModelWidget.cpp \
    $$PWD/StochasticMotionInput/src/VlachosEtAlModel.cpp 

HEADERS  += \
    $$PWD/UniformMotionInput.h \
    $$PWD/EarthquakeEventSelection.h \
    $$PWD/SHAMotionWidget.h \
    $$PWD/EarthquakeRecord.h \
    $$PWD/EDP_Selection.h \
    $$PWD/StandardEarthquakeEDP.h \
    $$PWD/ExistingPEER_Events.h \
    $$PWD/StochasticMotionInput/include/StochasticMotionInputWidget.h \
    $$PWD/StochasticMotionInput/include/StochasticModelWidget.h \    
    $$PWD/StochasticMotionInput/include/VlachosEtAlModel.h 

RESOURCES += \
    images.qrc \
    $$PWD/styles.qrc

#FORMS    += mainwindow.ui

#RESOURCES += \
#    schema.qrc

