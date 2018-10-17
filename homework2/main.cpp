#include <QCoreApplication>

#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>

namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< ��1��
    col02    =   0x00000001<<1,         //!< ��2��
    col03    =   0x00000001<<2,         //!< ��3��
    col04    =   0x00000001<<3,         //!< ��4��
    col05    =   0x00000001<<4,         //!< ��5��
    col06    =   0x00000001<<5,         //!< ��6��
    col07    =   0x00000001<<6,         //!< ��7��
    col08    =   0x00000001<<7,         //!< ��8��
    col09    =   0x00000001<<8,         //!< ��9��
    col10    =   0x00000001<<9,         //!< ��10��
    col11    =   0x00000001<<10,        //!< ��11��
    col12    =   0x00000001<<11,        //!< ��12��
    col13    =   0x00000001<<12,        //!< ��13��
    col14    =   0x00000001<<13,        //!< ��14��
    col15    =   0x00000001<<14,        //!< ��15��
    col16    =   0x00000001<<15,        //!< ��16��
    col17    =   0x00000001<<16,        //!< ��17��
    col18    =   0x00000001<<17,        //!< ��18��
    col19    =   0x00000001<<18,        //!< ��19��
    col20    =   0x00000001<<19,        //!< ��20��
    col21    =   0x00000001<<20,        //!< ��21��
    col22    =   0x00000001<<21,        //!< ��22��
    col23    =   0x00000001<<22,        //!< ��23��
    col24    =   0x00000001<<23,        //!< ��24��
    col25    =   0x00000001<<24,        //!< ��25��
    col26    =   0x00000001<<25,        //!< ��26��
    col27    =   0x00000001<<26,        //!< ��27��
    col28    =   0x00000001<<27,        //!< ��28��
    col29    =   0x00000001<<28,        //!< ��29��
    col30    =   0x00000001<<29,        //!< ��30��
    col31    =   0x00000001<<30,        //!< ��31��
    col32    =   0x00000001<<31,        //!< ��32��
};
}


typedef struct{
    // �벹ȫ�ṹ����
    QString num;
    QString name;
    QVector<int> core;
} studData;

QDebug operator<< (QDebug d, const studData &data) {
    // �벹ȫ��������غ�����ʹ�����ֱ�����studData�ṹ
    QDebugStateSaver saver(d);
    d.nospace()<<data.num<<" "<<data.name<<" "<<data.core;
    return d;
}

// �Ƚ��࣬����std::sort����������
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn) {
    case SK::col01:
        if(d1.name>=d2.name)
            result = false;
        else
            result = true;
        break;
    case SK::col02:
        if(d1.num>=d2.num)
            result = false;
        else
            result = true;
        break;
    default : result=(d1.core.at(currentColumn-3)>d2.core.at(currentColumn-3));
        break;
    }
    return result;

}


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    readFile();
    doSort(QString,int);
    QString tempFile;
};

 ScoreSorter::ScoreSorter(QString dataFile)
{
     tempFile=dataFile;
}
ScoreSorter::doSort(QString tempFile,int i)
{
    std::sort (tempFile.begin(),tempFile.end(),myCmp::operator (i));
}
ScoreSorter::readFile()
{
    QFile file(tempFile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return -1;
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        qDebug<<line;
    }
}

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
        switch (type) {
        case QtDebugMsg:
            fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
            break;
        case QtInfoMsg:
            fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
            break;
        case QtWarningMsg:
            fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
            break;
        case QtCriticalMsg:
            fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
            break;
        case QtFatalMsg:
            fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
            abort();
        }
}

int main ()
{
    int a;
    printf("����һ������");
    scanf("%d",&a);
    qInstallMessageHandler(myMessageOutput);
    QString datafile = "data.txt";

    // ���������ļ��Ѵ��ڣ���ɾ��֮
    QFile f("sorted_"+datafile);
    if (f.exists())
    {
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort(datafile,a);
    return 0;
}
