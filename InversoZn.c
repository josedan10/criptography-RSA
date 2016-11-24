/*<<< INVERSO MODULAR >>>*/
int Inverso_Zn(int prod, int coPrimoProd, int(*alg_euc_ext)(int, int)) {
	int inverso;

	inverso = (*alg_euc_ext)(prod, coPrimoProd);

	if (inverso<0)inverso += prod;
	return inverso;
};