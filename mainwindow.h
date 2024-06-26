#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_processButton_clicked();
    void on_generateEnglishButton_clicked();
    void on_generateRussianButton_clicked();
    void on_helpButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString processString(const QString &input);
    QString generateString(int wordCount, int wordLength, bool isRussian);
    bool startsWithVowel(const QString &word);
};

#endif // MAINWINDOW_H
