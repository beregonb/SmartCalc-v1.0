#include "credit.h"
/**
 * @brief Расчет ежемесячных выплат для дифференцированного кредита
 * 
 * @param every_month_credit - Указатель на переменную, в которую будет записана сумма ежемесячного платежа по основному долгу
 * @param mass_osnovn - Указатель на массив, в который будут записаны суммы ежемесячных платежей
 * @param persent_plat - Указатель на массив, в который будут записаны суммы ежемесячных платежей по процентам
 * @param ostatok_dolga - Указатель на массив, в который будут записаны остатки долга после каждого месяца
 * @param sum_credit - Общая сумма кредита
 * @param procent - Годовая процентная ставка по кредиту
 * @param months - Количество месяцев для выплаты кредита
 */
void credit_calc_diff(double *every_month_credit, double **mass_osnovn,
                      double **persent_plat, double **ostatok_dolga,
                      long double sum_credit, double procent, int months) {
    // Выделение памяти для массивов
    *mass_osnovn = malloc(sizeof(long double) * months);
    *persent_plat = malloc(sizeof(long double) * months);
    *ostatok_dolga = malloc(sizeof(long double) * months);

    // Расчет ежемесячного платежа по основному долгу
    *every_month_credit = sum_credit / months;
    long double sum_ras = sum_credit;

    // Итерация по каждому месяцу
    for (int i = 0; i < months; i++) {
        // Расчет основной части платежа
        long double telo_credit = sum_ras - (*every_month_credit * i);
        long double procent_credit = telo_credit * (procent / 100) / 12;

        // Запись платежа по процентам в массив
        (*persent_plat)[i] = procent_credit;

        // Расчет общего ежемесячного платежа
        long double every_month = *every_month_credit + procent_credit;

        // Запись ежемесячного платежа в массив
        (*mass_osnovn)[i] = every_month;

        // Расчет остатка долга
        sum_credit -= *every_month_credit;
        (*ostatok_dolga)[i] = sum_credit;
    }
}
/**
 * @param every_month_credit - Указатель на переменную, в которую будет записана сумма ежемесячного платежа по основному долгу
 * @param mass_osnovn - Указатель на массив, в который будут записаны суммы ежемесячных платежей
 * @param persent_plat - Указатель на массив, в который будут записаны суммы ежемесячных платежей по процентам
 * @param ostatok_dolga - Указатель на массив, в который будут записаны остатки долга после каждого месяца
 * @param sum_credit - Общая сумма кредита
 * @param procent - Годовая процентная ставка по кредиту
 * @param months - Количество месяцев для выплаты кредита
 */
void credit_calc_anyff(double *every_month_credit, double **mass_osnovn,
                       double **persent_plat, double **ostatok_dolga,
                       long double sum_credit, double procent, int months) {
    // Выделение памяти для массивов
    *mass_osnovn = malloc(sizeof(long double) * months);
    *persent_plat = malloc(sizeof(long double) * months);
    *ostatok_dolga = malloc(sizeof(long double) * months);

    // Расчет коэффициента автокредита
    long double j = procent / 12 / 100;
    long double koff_aut = j * powl(1 + j, months) / (powl(1 + j, months) - 1);

    // Расчет ежемесячного платежа
    *every_month_credit = sum_credit * koff_aut;

    for (int i = 0; i < months; i++) {
        // Расчет процентной части платежа
        long double p = j * sum_credit;
        (*persent_plat)[i] = p;

        // Расчет основной части платежа
        long double every_month = *every_month_credit - p;
        sum_credit -= every_month;

        // Заполнение массивов данными
        (*mass_osnovn)[i] = every_month;
        (*ostatok_dolga)[i] = sum_credit;
    }
}

// int main() {
//   double *arr;   // основной долг
//   double arr2;   // платеж
//   double *arr3;  // платеж по процентам
//   double *arr4;  // остаток долга

//   credit_calc_anyff(&arr2, &arr, &arr3, &arr4, 200000, 12, 24);

//   for (int i = 0; i < 24; i++) {
//     printf(
//         "Сумма платежа - %f |  Платеж по основному долгу - %f | Платеж по "
//         "процентам - %f |  Остаток долга - %f\n",
//         arr2, arr[i], arr3[i], arr4[i]);
//   }
//   free(arr);
//   free(arr3);
//   free(arr4);
//   printf("\n");
//   credit_calc_diff(&arr2, &arr, &arr3, &arr4, 200000, 12, 24);
//   for (int i = 0; i < 24; i++) {
//     printf(
//         "Сумма платежа - %f |  Платеж по основному долгу - %f | Платеж по "
//         "процентам - %f |  Остаток долга - %f\n",
//         arr[i], arr2, arr3[i], arr4[i]);
//   }
//   free(arr);
//   free(arr3);
//   free(arr4);

//   return 0;
// }
