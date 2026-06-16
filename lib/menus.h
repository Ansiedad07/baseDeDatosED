#include <stdio.h>

int menuPrincipal(void);

int menuPrincipal(void) {
    int op;
    printf("\n-= Menu Principal =-\n");
    printf("1. Altas (agregar persona)\n");
    printf("2. Mostrar cola\n");
    printf("3. Bajas (eliminar persona)\n");
    printf("4. Salir\n");
    printf("Opcion: ");
    scanf("%d", &op);
    return op;
}