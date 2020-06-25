#include <floyd.h>
#include "bus.h"

void create_route_red(Vehicle* bus) {
    LinkedList *l = create_linked_list();
    int* destinations = calloc(12, sizeof(int));
    destinations[0] = Y006R;
    int *path = floyd_path(Y006R,G005S);
    for (int i = 1; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[1] = G005S;
    path = floyd_path(G005S, A001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[2] = A001S;
    path = floyd_path(A001S, D001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[3] = D001S;
    path = floyd_path(D001S, F002S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[4] = F002S;
    path = floyd_path(F002S, L004S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[5] = L004S;
    path = floyd_path(L004S, R002S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[6] = R002S;
    path = floyd_path(R002S, X005S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[7] = X005S;
    path = floyd_path(X005S, U005S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[8] = U005S;
    path = floyd_path(U005S, S006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[9] = S006S;
    path = floyd_path(S006S, M001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[10] = M001S;
    path = floyd_path(M001S, Y006R);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[11] = -1;
    bus->destinations = destinations;
    bus->current_route = l;
}

void create_route_green(Vehicle* bus) {
    LinkedList *l = create_linked_list();
    int* destinations = calloc(7, sizeof(int));
    destinations[0] = Y006R;
    int *path = floyd_path(Y006R,G006S);
    for (int i = 1; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[1] = G006S;
    path = floyd_path(G006S, B001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[2] = B001S;
    path = floyd_path(B001S, E002S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[3] = E002S;
    path = floyd_path(E002S, L003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[4] = L003S;
    path = floyd_path(L003S, Z006R);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[5] = Z006R;
    path = floyd_path(Z006R, Y006R);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[6] = -1;
    bus->destinations = destinations;
    bus->current_route = l;
}

void create_route_blue(Vehicle* bus) {
    LinkedList *l = create_linked_list();
    int* destinations = calloc(7, sizeof(int));
    destinations[0] = Y006R;
    int *path = floyd_path(Y006R, Z006R);
    for (int i = 1; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[1] = Z006R;
    path = floyd_path(Z006R, R003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[2] = R003S;
    path = floyd_path(R003S, W005S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[3] = W005S;
    path = floyd_path(W005S, T006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[4] = T006S;
    path = floyd_path(T006S, M006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[5] = M006S;
    path = floyd_path(M006S, Y006R);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[6] = -1;
    bus->destinations = destinations;
    bus->current_route = l;
}

void create_route_white(Vehicle* bus) {
    LinkedList *l = create_linked_list();
    int* destinations = calloc(7, sizeof(int));
    destinations[0] = C001S;
    int *path = floyd_path(C001S, I004S);
    for (int i = 1; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[1] = I004S;
    path = floyd_path(I004S, O003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[2] = O003S;
    path = floyd_path(O003S, T005S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[3] = T005S;
    path = floyd_path(T005S, N001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[4] = N001S;
    path = floyd_path(N001S, H006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[5] = H006S;
    path = floyd_path(H006S, C001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[6] = -1;
    bus->destinations = destinations;
    bus->current_route = l;
}

void create_route_gray(Vehicle* bus) {
    LinkedList *l = create_linked_list();
    int* destinations = calloc(7, sizeof(int));
    destinations[0] = D001S;
    int *path = floyd_path(D001S, J004S);
    for (int i = 1; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[1] = J004S;
    path = floyd_path(J004S, P003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[2] = P003S;
    path = floyd_path(P003S, U005S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[3] = U005S;
    path = floyd_path(U005S, O001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[4] = O001S;
    path = floyd_path(O001S, I006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[5] = I006S;
    path = floyd_path(I006S, D001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[6] = -1;
    bus->destinations = destinations;
    bus->current_route = l;
}

void create_route_black(Vehicle* bus) {
    LinkedList *l = create_linked_list();
    int* destinations = calloc(7, sizeof(int));
    destinations[0] = E001S;
    int *path = floyd_path(E001S, K004S);
    for (int i = 1; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[1] = K004S;
    path = floyd_path(K004S, Q003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[2] = Q003S;
    path = floyd_path(Q003S, V005S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[3] = V005S;
    path = floyd_path(V005S, P001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[4] = P001S;
    path = floyd_path(P001S, J006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[5] = J006S;
    path = floyd_path(J006S, E001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[6] = -1;
    bus->destinations = destinations;
    bus->current_route = l;
}

void create_route_pink(Vehicle* bus) {
    LinkedList *l = create_linked_list();
    int* destinations = calloc(5, sizeof(int));
    destinations[0] = A001S;
    int *path = floyd_path(A001S, F002S);
    for (int i = 1; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[1] = F002S;
    path = floyd_path(F002S, F005S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[2] = F005S;
    path = floyd_path(F005S, A006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[3] = A006S;
    path = floyd_path(A006S, A001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[4] = -1;
    bus->destinations = destinations;
    bus->current_route = l;
}

void create_route_light_blue(Vehicle* bus) {
    LinkedList *l = create_linked_list();
    int* destinations = calloc(5, sizeof(int));
    destinations[0] = S001S;
    int *path = floyd_path(S001S, X002S);
    for (int i = 1; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[1] = X002S;
    path = floyd_path(X002S, X005S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[2] = X005S;
    path = floyd_path(X005S, S006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[3] = S006S;
    path = floyd_path(S006S, S001S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[4] = -1;
    bus->destinations = destinations;
    bus->current_route = l;
}

void create_route_orange(Vehicle* bus) {
    LinkedList *l = create_linked_list();
    int* destinations = calloc(23, sizeof(int));
    destinations[0] = A008S;
    int *path = floyd_path(A008S, A003S);
    for (int i = 1; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[1] = A003S;
    path = floyd_path(A003S, M003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[2] = M003S;
    path = floyd_path(M003S, O006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[3] = O006S;
    path = floyd_path(O006S, C008S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[4] = C008S;
    path = floyd_path(C008S, C003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[5] = C003S;
    path = floyd_path(C003S, O003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[6] = O003S;
    path = floyd_path(O003S, Q006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[7] = Q006S;
    path = floyd_path(Q006S, E008S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[8] = E008S;
    path = floyd_path(E008S, E003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[9] = E003S;
    path = floyd_path(E003S, Q003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[10] = Q003S;
    path = floyd_path(Q003S, X004S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[11] = X004S;
    path = floyd_path(X004S, X007S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[12] = X007S;
    path = floyd_path(X007S, L006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[13] = L006S;
    path = floyd_path(L006S, J003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[14] = J003S;
    path = floyd_path(J003S, V004S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[15] = V004S;
    path = floyd_path(V004S, V007S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[16] = V007S;
    path = floyd_path(V007S, J006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[17] = J006S;
    path = floyd_path(J006S, H003S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[18] = H003S;
    path = floyd_path(H003S, T004S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[19] = T004S;
    path = floyd_path(T004S, T007S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[20] = T007S;
    path = floyd_path(T007S, H006S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[21] = H006S;
    path = floyd_path(H006S, A008S);
    for (int i = 2; i <= path[0]; i++) {
        append(l, create_node(path[i]));
    }
    free(path);
    destinations[22] = -1;
    bus->destinations = destinations;
    bus->current_route = l;
}
