#include <stdio.h>
#include <string.h>

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { const char *message = test(); tests_run++; if (message) return message; } while (0)

int tests_run=0;

const char* categorize_age(int age)
{
 if (age < 0) {
 return "Invalid age";
 }
 else if (age < 13) {
 return "Child";
 }
 else if (age < 20) {
 return "Teenager";
 }
 else if (age < 65) {
 return "Adult";
 }
 else {
 return "Senior";
 }
}

static const char* age_inferieur_a_0()
{
    const char* a= categorize_age(-2);
    mu_assert("l'age n'est pas valide\n",a=="Invalid age");
    return 0;
}

static const char* age_inferieur_a_13()
{
    const char* a= categorize_age(8);
    mu_assert("l'age n'est pas valide\n",a=="Child");
    return 0;
}

static const char* age_inferieur_a_20()
{
    const char* a= categorize_age(17);
    mu_assert("l'age n'est pas valide\n",a=="Teenager");
    return 0;
}

static const char* age_inferieur_a_65()
{
    const char* a= categorize_age(53);
    mu_assert("l'age n'est pas valide\n",a=="Adult");
    return 0;
}

static const char* age_superieur_a_65()
{
    const char* a= categorize_age(95);
    mu_assert("l'age n'est pas valide\n",a=="Age invalide");
    return 0;
}


static const char* all_tests(){
    mu_run_test(age_inferieur_a_0);
    mu_run_test(age_inferieur_a_13);
    mu_run_test(age_inferieur_a_20);
    mu_run_test(age_inferieur_a_65);
    mu_run_test(age_superieur_a_65);

    return 0;
}

int main()
{
 const char *result = all_tests(); // on lance tous les tests
 if (result != 0) // il y a eu une erreur
 {
    printf("%s\n", result); // on affiche le message d’erreur
 }
 else
 {
    printf("All tests passed.\n");
 }
    printf("Tests run: %d\n", tests_run); // on affiche le nombre de tests lancés
 return result != 0;
}