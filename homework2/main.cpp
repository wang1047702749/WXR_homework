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
    case SK::col03:
        if(d1.core.at(0)>=d2.core.at(0))
            result = false;
        else
            result = true;
        break;
    case SK::col04:
       if(d1.core.at(1)>=d2.core.at(1))
           result = false;
       else
           result = true;
       break;
    case SK::col05:
       if(d1.core.at(2)>=d2.core.at(2))
           result = false;
       else
           result = true;
       break;
    case SK::col06:
       if(d1.core.at(3)>=d2.core.at(3))
           result = false;
       else
           result = true;
       break;
    case SK::col07:
       if(d1.core.at(4)>=d2.core.at(4))
           result = false;
       else
           result = true;
       break;
    case SK::col08:
       if(d1.core.at(5)>=d2.core.at(5))
           result = false;
       else
           result = true;
       break;
    case SK::col09:
       if(d1.core.at(6)>=d2.core.at(6))
           result = false;
       else
           result = true;
       break;
    case SK::col10:
       if(d1.core.at(7)>=d2.core.at(7))
           result = false;
       else
           result = true;
       break;
    case SK::col11:
       if(d1.core.at(8)>=d2.core.at(8))
           result = false;
       else
           result = true;
       break;
    case SK::col12:
       if(d1.core.at(9)>=d2.core.at(9))
           result = false;
       else
           result = true;
       break;
    case SK::col13:
       if(d1.core.at(10)>=d2.core.at(10))
           result = false;
       else
           result = true;
       break;
    case SK::col14:
       if(d1.core.at(11)>=d2.core.at(11))
           result = false;
       else
           result = true;
       break;
    case SK::col15:
       if(d1.core.at(12)>=d2.core.at(12))
           result = false;
       else
           result = true;
       break;
    case SK::col16:
       if(d1.core.at(13)>=d2.core.at(13))
           result = false;
       else
           result = true;
       break;
    case SK::col17:
       if(d1.core.at(14)>=d2.core.at(14))
           result = false;
       else
           result = true;
       break;
    case SK::col18:
       if(d1.core.at(15)>=d2.core.at(15))
           result = false;
       else
           result = true;
       break;
    case SK::col19:
       if(d1.core.at(16)>=d2.core.at(16))
           result = false;
       else
           result = true;
       break;
    case SK::col20:
       if(d1.core.at(17)>=d2.core.at(17))
           result = false;
       else
           result = true;
       break;
    case SK::col21:
       if(d1.core.at(18)>=d2.core.at(18))
           result = false;
       else
           result = true;
       break;
    case SK::col22:
       if(d1.core.at(19)>=d2.core.at(19))
           result = false;
       else
           result = true;
       break;
    case SK::col23:
       if(d1.core.at(20)>=d2.core.at(20))
           result = false;
       else
           result = true;
       break;
    case SK::col24:
       if(d1.core.at(21)>=d2.core.at(21))
           result = false;
       else
           result = true;
       break;
    case SK::col25:
       if(d1.core.at(22)>=d2.core.at(22))
           result = false;
       else
           result = true;
       break;
    case SK::col26:
       if(d1.core.at(23)>=d2.core.at(24))
           result = false;
       else
           result = true;
       break;
    case SK::col27:
       if(d1.core.at(25)>=d2.core.at(25))
           result = false;
       else
           result = true;
       break;
    case SK::col28:
       if(d1.core.at(26)>=d2.core.at(26))
           result = false;
       else
           result = true;
       break;
    case SK::col29:
       if(d1.core.at(27)>=d2.core.at(27))
           result = false;
       else
           result = true;
       break;
    case SK::col30:
       if(d1.core.at(28)>=d2.core.at(28))
           result = false;
       else
           result = true;
       break;
    case SK::col31:
       if(d1.core.at(29)>=d2.core.at(29))
           result = false;
       else
           result = true;
       break;
    case SK::col32:
       if(d1.core.at(30)>=d2.core.at(30))
           result = false;
       else
           result = true;
       break;


    // ...
    // �벹ȫ��������غ���
    // ...
    //
    }
    return result;

}


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);

    // ...
    // �벹ȫ���࣬ʹ��ʵ������Ҫ��
    // ...
}

// �벹ȫ
ScoreSorter::ScoreSorter(QString dataFile){
     sort(s_name.begin(),s_name.end(),c_name);
}


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // �Զ���qDebug
}

int main()
{
    qInstallMessageHandler(myMessageOutput);
    QString datafile = "data.txt";

    // ���������ļ��Ѵ��ڣ���ɾ��֮
    QFile f("sorted_"+datafile);
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}
