#include<stdio.h>
#include<gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
GtkWidget *new_med_name,*edit_details,*new_med_id,*new_med_company,*new_med_mfg,*new_med_exp,*new_med_price,*new_med_quantity,*del_entry,*add_cus_entry,*add_emp_entry,*edit_entry_id,*med_name,*med_price,*med_quantity,*med_md,*med_ed, *edit_window,*editfs_window,*editff_window,*cust_bill_id,*tab_quantity,*veri_id_entry,*verci_id_entry;
GtkWidget *med_found;
GtkWidget *dis_button;
GtkWidget *add_button;
GtkWidget *del_button;
GtkWidget *edit_button;
GtkWidget *buy_med_button;
GtkWidget *add_cus_button;
GtkWidget *add_emp_button;
GtkWidget *dis_cus_button;
GtkWidget *buy_cus_med_button;
void add_employeef();
void add_emp_buttonf();
void verify_but_eid();
void verify_id_login();
void add_customerf();
void add_cus_buttonf();
void verify_cid_login();
void struct_intialization();
void display_medicine();
void copy_medicine();
void add_medicine();
void file_update();
int find_medicine_index_id(int );
int find_medicine_index(char []);
void edit_medicinef();
void edit_medicine_det();
void edit_medicine();
void delete_medicine();
void delete_button();
void customer_billing();
void add_cart();
void add_item_to_cart();
void generate_bill();
void view_cart();
void add_employeef(){
    FILE *employee_ids;
    const char *new_emp_id;
    char new_id_emp[10];
    new_emp_id=gtk_entry_get_text(GTK_ENTRY(add_emp_entry));
    strcpy(new_id_emp,new_emp_id);
    employee_ids=fopen("employee.txt","a");
    rewind(employee_ids);
    fprintf(employee_ids,"%s\n",new_id_emp);
    fclose(employee_ids);
}
void add_emp_buttonf(){
    GtkWidget *add_emp_window;
    add_emp_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *add_emp_table;
    GtkWidget *label,*add_employee_id,*add_emp_id;
    add_emp_table=gtk_table_new(8,10,FALSE);
    label=gtk_label_new("VVR PHARMACY");
    add_emp_id=gtk_label_new("Enter the id of the new employee:");
    add_employee_id=gtk_button_new_with_label("ADD EMPLOYEE");
    add_emp_entry=gtk_entry_new();
    gtk_table_attach_defaults(GTK_TABLE(add_emp_table),label,0,2,0,1);
    gtk_table_attach_defaults(GTK_TABLE(add_emp_table),add_emp_id,0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(add_emp_table),add_emp_entry,1,2,1,2);
    gtk_table_attach_defaults(GTK_TABLE(add_emp_table),add_employee_id,0,2,2,3);
    g_signal_connect(add_employee_id,"clicked",G_CALLBACK(add_employeef),NULL);
    gtk_container_add(GTK_CONTAINER(add_emp_window),add_emp_table);
    gtk_widget_show_all(add_emp_window);
    gtk_main();
}
void verify_but_eid(){
    GtkWidget *veri_window;
    veri_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *veri_table;
    GtkWidget *veri_mlabel,*veri_id_label;
    GtkWidget *verify_id;
    dis_button=gtk_button_new_with_label("Display medicine");
    add_button=gtk_button_new_with_label("Add medicine");
    edit_button=gtk_button_new_with_label("Edit medicine");
    del_button=gtk_button_new_with_label("Delete medicine");
    buy_med_button=gtk_button_new_with_label("Buy medicine");
    add_cus_button=gtk_button_new_with_label("Add customer");
    add_emp_button=gtk_button_new_with_label("Add employee");
    verify_id=gtk_button_new_with_label("Verify employee id");
    veri_mlabel=gtk_label_new("EMPLOYEE WINDOW");
    veri_id_label=gtk_label_new("Enter your employee id: ");
    veri_id_entry=gtk_entry_new();
    veri_table=gtk_table_new(8,10,FALSE);
    gtk_table_attach_defaults(GTK_TABLE(veri_table),veri_mlabel,0,2,0,1);
    gtk_table_attach_defaults(GTK_TABLE(veri_table),veri_id_label,0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(veri_table),veri_id_entry,1,2,1,2);
    gtk_table_attach_defaults(GTK_TABLE(veri_table),verify_id,0,2,2,3);
    gtk_table_attach_defaults(GTK_TABLE(veri_table),dis_button,0,2,3,4);
    gtk_table_attach_defaults(GTK_TABLE(veri_table),add_button,0,2,4,5);
    gtk_table_attach_defaults(GTK_TABLE(veri_table),del_button,0,2,5,6);
    gtk_table_attach_defaults(GTK_TABLE(veri_table),edit_button,0,2,6,7);
    gtk_table_attach_defaults(GTK_TABLE(veri_table),buy_med_button,0,2,7,8);
    gtk_table_attach_defaults(GTK_TABLE(veri_table),add_cus_button,0,2,8,9);
    gtk_table_attach_defaults(GTK_TABLE(veri_table),add_emp_button,0,2,9,10);
    g_signal_connect(verify_id,"clicked",G_CALLBACK(verify_id_login),NULL);
    gtk_widget_set_sensitive(dis_button,FALSE);
    gtk_widget_set_sensitive(add_button,FALSE);
    gtk_widget_set_sensitive(del_button,FALSE);
    gtk_widget_set_sensitive(edit_button,FALSE);
    gtk_widget_set_sensitive(buy_med_button,FALSE);
    gtk_widget_set_sensitive(add_cus_button,FALSE);
    gtk_widget_set_sensitive(add_emp_button,FALSE);
    g_signal_connect(dis_button,"clicked",G_CALLBACK(display_medicine),NULL);
    g_signal_connect(del_button,"clicked",G_CALLBACK(delete_button),NULL);
    g_signal_connect(add_button,"clicked",G_CALLBACK(add_medicine),NULL);
    g_signal_connect(edit_button,"clicked",G_CALLBACK(edit_medicine),NULL);
    g_signal_connect(add_cus_button,"clicked",G_CALLBACK(add_cus_buttonf),NULL);
    g_signal_connect(add_emp_button,"clicked",G_CALLBACK(add_emp_buttonf),NULL);
    g_signal_connect(buy_med_button,"clicked",G_CALLBACK(customer_billing),NULL);
    gtk_container_add(GTK_CONTAINER(veri_window),veri_table);
    gtk_widget_show_all(veri_window);
    gtk_main();
}
void verify_id_login(){
    FILE *employee_ids;
    const char *id_entry;
    char id[7];
    char id_ver[7];
    int res;
    id_entry=gtk_entry_get_text(GTK_ENTRY(veri_id_entry));
    strcpy(id,id_entry);
    employee_ids=fopen("employee.txt","r");
    rewind(employee_ids);
    while ((fscanf(employee_ids,"%s",id_ver))!=EOF)
    {
        res=strcmp(id,id_ver);
        if(res==0){
        break;
        }
    }
    fclose(employee_ids);
    if(res==0){
    gtk_widget_set_sensitive(dis_button,TRUE);
    gtk_widget_set_sensitive(add_button,TRUE);
    gtk_widget_set_sensitive(del_button,TRUE);
    gtk_widget_set_sensitive(edit_button,TRUE);
    gtk_widget_set_sensitive(buy_med_button,TRUE);
    gtk_widget_set_sensitive(add_cus_button,TRUE);
    gtk_widget_set_sensitive(add_emp_button,TRUE);
    }
    else{
    	GtkWidget *veriif_label,*veriif_table;
    	GtkWidget *veriif_window;
        veriif_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_default_size(GTK_WINDOW(veriif_window), 200, 200);
         veriif_table=gtk_table_new(6,6,FALSE);
         veriif_label=gtk_label_new("Login unsuccessfull");
          gtk_table_attach_defaults(GTK_TABLE(veriif_table),veriif_label,3,5,4,5);
          gtk_container_add(GTK_CONTAINER(veriif_window),veriif_table);
	gtk_widget_show_all (veriif_window);
	gtk_main ();
    }
}
void add_customerf(){
    FILE *customer_ids;
    const char *new_cus_id;
    char new_id[10];
    new_cus_id=gtk_entry_get_text(GTK_ENTRY(add_cus_entry));
    strcpy(new_id,new_cus_id);
    customer_ids=fopen("customer.txt","a");
    rewind(customer_ids);
    fprintf(customer_ids,"%s\n",new_id);
    fclose(customer_ids);
}
void add_cus_buttonf(){
    GtkWidget *add_cus_window;
    add_cus_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *add_cus_table;
    GtkWidget *label,*add_customer_id,*add_cus_id;
    add_cus_table=gtk_table_new(8,10,FALSE);
    label=gtk_label_new("VVR PHARMACY");
    add_cus_id=gtk_label_new("Enter the id of the new customer:");
    add_customer_id=gtk_button_new_with_label("ADD CUSTOMER");
    add_cus_entry=gtk_entry_new();
    gtk_table_attach_defaults(GTK_TABLE(add_cus_table),label,0,2,0,1);
    gtk_table_attach_defaults(GTK_TABLE(add_cus_table),add_cus_id,0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(add_cus_table),add_cus_entry,1,2,1,2);
    gtk_table_attach_defaults(GTK_TABLE(add_cus_table),add_customer_id,0,2,2,3);
    g_signal_connect(add_customer_id,"clicked",G_CALLBACK(add_customerf),NULL);
    gtk_container_add(GTK_CONTAINER(add_cus_window),add_cus_table);
    gtk_widget_show_all(add_cus_window);
    gtk_main();
}
void verify_but_ecid(){
    GtkWidget *verci_window;
    verci_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *verci_table;
    GtkWidget *verci_mlabel,*verci_id_label;
    GtkWidget *verify_cid;
    dis_cus_button=gtk_button_new_with_label("Display medicine");
    buy_cus_med_button=gtk_button_new_with_label("Buy medicine");
    verify_cid=gtk_button_new_with_label("Verify customer id");
    verci_mlabel=gtk_label_new("CUSTOMER WINDOW");
    verci_id_label=gtk_label_new("Enter your customer id: ");
    verci_id_entry=gtk_entry_new();
    verci_table=gtk_table_new(8,10,FALSE);
    gtk_table_attach_defaults(GTK_TABLE(verci_table),verci_mlabel,0,2,0,1);
    gtk_table_attach_defaults(GTK_TABLE(verci_table),verci_id_label,0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(verci_table),verci_id_entry,1,2,1,2);
    gtk_table_attach_defaults(GTK_TABLE(verci_table),verify_cid,0,2,2,3);
    gtk_table_attach_defaults(GTK_TABLE(verci_table),dis_cus_button,0,2,3,4);
    gtk_table_attach_defaults(GTK_TABLE(verci_table),buy_cus_med_button,0,2,4,5);
    g_signal_connect(verify_cid,"clicked",G_CALLBACK(verify_cid_login),NULL);
    gtk_widget_set_sensitive(dis_cus_button,FALSE);
    gtk_widget_set_sensitive(buy_cus_med_button,FALSE);
    g_signal_connect(dis_cus_button,"clicked",G_CALLBACK(display_medicine),NULL);
    g_signal_connect(buy_cus_med_button,"clicked",G_CALLBACK(customer_billing),NULL);
    gtk_container_add(GTK_CONTAINER(verci_window),verci_table);
    gtk_widget_show_all(verci_window);
    gtk_main();
}
void verify_cid_login(){
    FILE *customer_ids;
    const char *cid_entry;
    char cid[7];
    char cid_ver[7];
    int cres;
    cid_entry=gtk_entry_get_text(GTK_ENTRY(verci_id_entry));
    strcpy(cid,cid_entry);
    customer_ids=fopen("customer.txt","r");
    rewind(customer_ids);
    while ((fscanf(customer_ids,"%s",cid_ver))!=EOF)
    {
        cres=strcmp(cid,cid_ver);
        if(cres==0){
        break;
        }
    }
    fclose(customer_ids);
    if(cres==0){
    gtk_widget_set_sensitive(dis_cus_button,TRUE);
    gtk_widget_set_sensitive(buy_cus_med_button,TRUE);
    }
    else{
    	GtkWidget *verciif_label,*verciif_table;
    	GtkWidget *verciif_window;
        verciif_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_default_size(GTK_WINDOW(verciif_window), 200, 200);
         verciif_table=gtk_table_new(6,6,FALSE);
         verciif_label=gtk_label_new("Login unsuccessfull");
          gtk_table_attach_defaults(GTK_TABLE(verciif_table),verciif_label,3,5,4,5);
          gtk_container_add(GTK_CONTAINER(verciif_window),verciif_table);
	gtk_widget_show_all (verciif_window);
	gtk_main ();
    }
}


struct Medicine{
   int id,price,quantity;
   char medicineName[100],Company[100],Mfg_Date[11],Exp_Date[11];
};
struct Medicine m[100];
struct billing_item{
    int quantity,med_id;
    int index;
};

int counter=0;
int i=0;
void struct_intialization(){
    FILE *medicine;
    medicine=fopen("medicines.txt","r");
    rewind(medicine);
    char str[500];
    while ((fscanf(medicine,"%s",str))!=EOF)
    {
        char *part;
        part=strtok(str,",");
        m[i].id=atoi(part);
        part=strtok(NULL,",");
        sprintf(m[i].medicineName,"%s",part);
        part=strtok(NULL,",");
        sprintf(m[i].Company,"%s",part);
        part=strtok(NULL,",");
        m[i].price=atoi(part);
        part=strtok(NULL,",");
        sprintf(m[i].Mfg_Date,"%s",part);        
        part=strtok(NULL,",");
        sprintf(m[i].Exp_Date,"%s",part);
        part=strtok(NULL,",");
        m[i].quantity=atoi(part);
        i++;
        counter++;
    }
}
void display_medicine(){
	GtkWidget *dis_window;
	dis_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(dis_window), 400, 300);
	GtkWidget *medicine_table;
	medicine_table=gtk_table_new(counter,7,TRUE);
	GtkWidget *medicinenamemain;
        GtkWidget *companymain;
        GtkWidget *medicineidmain;
        GtkWidget *Mfgdatemain;
        GtkWidget *Expdatemain;
        GtkWidget *mpricemain;
        GtkWidget *mquantitymain;
        companymain=gtk_label_new("COMPANY");
        medicinenamemain=gtk_label_new("MEDICINE NAME");
        medicineidmain=gtk_label_new("MEDICINE ID");
        mpricemain=gtk_label_new("PRICE");
        mquantitymain=gtk_label_new("QUANTITY");
        Mfgdatemain=gtk_label_new("MFG_DATE");
        Expdatemain=gtk_label_new("EXP_DATE");
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),medicineidmain,0,1,0,1);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),medicinenamemain,1,2,0,1);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),companymain,2,3,0,1);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),Mfgdatemain,3,4,0,1);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),Expdatemain,4,5,0,1);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),mpricemain,5,6,0,1);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),mquantitymain,6,7,0,1);
    	for (int j = 0; j < counter; j++)
    	{
        GtkWidget *medicinename;
        GtkWidget *company;
        GtkWidget *medicineid;
        GtkWidget *Mfgdate;
        GtkWidget *Expdate;
        GtkWidget *mprice;
        GtkWidget *mquantity;
        char medicine_id[10];
        char price[10];
        char quantity[10];
        sprintf(medicine_id,"%d",m[j].id);
        sprintf(price,"%d",m[j].price);
        sprintf(quantity,"%d",m[j].quantity);
        medicinename=gtk_label_new(m[j].medicineName);
        Mfgdate=gtk_label_new(m[j].Mfg_Date);
        Expdate=gtk_label_new(m[j].Exp_Date);
        company=gtk_label_new(m[j].Company);
     	mprice=gtk_label_new(price);
     	medicineid=gtk_label_new(medicine_id);
     	mquantity=gtk_label_new(quantity);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),medicineid,0,1,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),medicinename,1,2,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),company,2,3,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),Mfgdate,3,4,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),Expdate,4,5,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),mprice,5,6,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(medicine_table),mquantity,6,7,j+1,j+2);
    	}
    	gtk_container_add(GTK_CONTAINER(dis_window),medicine_table);
    	gtk_widget_show_all(dis_window);
    	gtk_main();
}
void copy_medicine(){
	const char *medicinename,*medicinemfg,*medicinecompany,*medicineexp;
	const char *medicineid,*medicineprice,*medicinequantity;
	medicinename=gtk_entry_get_text(GTK_ENTRY(new_med_name));
	medicineid=gtk_entry_get_text(GTK_ENTRY(new_med_id));
	medicinecompany=gtk_entry_get_text(GTK_ENTRY(new_med_company));
	medicinemfg=gtk_entry_get_text(GTK_ENTRY(new_med_mfg));
	medicineexp=gtk_entry_get_text(GTK_ENTRY(new_med_exp));
	medicineprice=gtk_entry_get_text(GTK_ENTRY(new_med_price));
	medicinequantity=gtk_entry_get_text(GTK_ENTRY(new_med_quantity));
	strcpy(m[counter].medicineName,medicinename);
	strcpy(m[counter].Company,medicinecompany);
	strcpy(m[counter].Mfg_Date,medicinemfg);
	strcpy(m[counter].Exp_Date,medicineexp);
	m[counter].id=atoi(medicineid);
	m[counter].price=atoi(medicineprice);
	m[counter].quantity=atoi(medicinequantity);
	counter++;
	file_update();
}
void add_medicine(){
	GtkWidget *add_window;
	add_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(add_window), 200, 300);
	GtkWidget *maintitle,*count,*med_name,*med_id,*med_company,*med_mfg,*med_exp,*med_price,*med_quantity;
	GtkWidget *add_table;
	GtkWidget *copy_button;
	char med_count[2];
	sprintf(med_count,"%d",counter);
	add_table=gtk_table_new(8,10,FALSE);
	copy_button=gtk_button_new_with_label("ADD MEDICINE");
	g_signal_connect(copy_button,"clicked",G_CALLBACK(copy_medicine),NULL);
	maintitle=gtk_label_new("Number of medicines already available:");
	med_name=gtk_label_new("Enter the medicine name:");
	med_id=gtk_label_new("Enter the medicine id:");
	med_company=gtk_label_new("Enter the medicine company:");
	med_mfg=gtk_label_new("Enter the medicine mfg date:");
	med_exp=gtk_label_new("Enter the medicine exp date:");
	med_price=gtk_label_new("Enter the medicine price:");
	med_quantity=gtk_label_new("Enter the medicine quantity:");
	count=gtk_label_new(med_count);
	new_med_name=gtk_entry_new();
	new_med_id=gtk_entry_new();
	new_med_company=gtk_entry_new();
	new_med_mfg=gtk_entry_new();
	new_med_exp=gtk_entry_new();
	new_med_price=gtk_entry_new();
	new_med_quantity=gtk_entry_new();
	gtk_table_attach_defaults(GTK_TABLE(add_table),maintitle,0,1,0,1);
        gtk_table_attach_defaults(GTK_TABLE(add_table),count,1,2,0,1);
        gtk_table_attach_defaults(GTK_TABLE(add_table),med_id,0,1,1,2);
        gtk_table_attach_defaults(GTK_TABLE(add_table),new_med_id,1,2,1,2);
        gtk_table_attach_defaults(GTK_TABLE(add_table),med_name,0,1,2,3);
        gtk_table_attach_defaults(GTK_TABLE(add_table),new_med_name,1,2,2,3);
        gtk_table_attach_defaults(GTK_TABLE(add_table),med_company,0,1,3,4);
        gtk_table_attach_defaults(GTK_TABLE(add_table),new_med_company,1,2,3,4);
        gtk_table_attach_defaults(GTK_TABLE(add_table),med_mfg,0,1,4,5);
        gtk_table_attach_defaults(GTK_TABLE(add_table),new_med_mfg,1,2,4,5);
        gtk_table_attach_defaults(GTK_TABLE(add_table),med_exp,0,1,5,6);
        gtk_table_attach_defaults(GTK_TABLE(add_table),new_med_exp,1,2,5,6);
        gtk_table_attach_defaults(GTK_TABLE(add_table),med_price,0,1,6,7);
        gtk_table_attach_defaults(GTK_TABLE(add_table),new_med_price,1,2,6,7);
        gtk_table_attach_defaults(GTK_TABLE(add_table),med_quantity,0,1,7,8);
        gtk_table_attach_defaults(GTK_TABLE(add_table),new_med_quantity,1,2,7,8);
        gtk_table_attach_defaults(GTK_TABLE(add_table),copy_button,0,2,8,9);
    	gtk_container_add(GTK_CONTAINER(add_window),add_table);
    	gtk_widget_show_all(add_window);
    	gtk_main();
}
void file_update(){
    FILE *medicinef;
    medicinef=fopen("medicines.txt","w");
    for (int k = 0; k < counter; k++)
    {
        fprintf(medicinef,"%d,",m[k].id);
        fprintf(medicinef,"%s,",m[k].medicineName);
        fprintf(medicinef,"%s,",m[k].Company);
        fprintf(medicinef,"%d,",m[k].price);
        fprintf(medicinef,"%s,",m[k].Mfg_Date);
        fprintf(medicinef,"%s,",m[k].Exp_Date);
        fprintf(medicinef,"%d\n",m[k].quantity);
    }
    fclose(medicinef);
}
int find_medicine_index_id(int index_check){
    int l=0;
    for (l = 0; l < counter; l++)
    {
        if(m[l].id==index_check){
            return l;
        }
    }
    return -1;
}
int find_medicine_index(char med_name[]){
    int l=0;
    for (l = 0; l < counter; l++)
    {
        if(strcmp(m[l].medicineName,med_name)==0){
            return l;
        }
    }
    return -1;
}
int indexe;
void edit_medicinef(){
	const char *edit_id;
	int edit_idf;
	edit_id=gtk_entry_get_text(GTK_ENTRY(edit_entry_id));
	edit_idf=atoi(edit_id);
	indexe=find_medicine_index_id(edit_idf);
	printf("%d",indexe);
	if(indexe==-1){
                GtkWidget *editff_label,*editff_table;
                editff_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
                editff_table=gtk_table_new(6,6,FALSE);
                editff_label=gtk_label_new("Medicine not available with the given id");
                gtk_table_attach_defaults(GTK_TABLE(editff_table),editff_label,3,5,4,5);
                gtk_container_add(GTK_CONTAINER(editff_window),editff_table);
		gtk_widget_show_all (editff_window);
		gtk_main ();
            }
        else{
                GtkWidget *editfs_label,*editfs_table;
                //GtkWidget *med_name,*med_price,*med_quantity,*med_md,*med_ed;
    		GtkWidget *med_namel,*med_pricel,*med_quantityl,*med_mdl,*med_edl;
    		GtkWidget *editfs_details;
    		char *mede_name,*mede_md,*mede_ed,*mede_price,*mede_qty;
    		char medq[100],medp[100];
                editfs_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
                editfs_table=gtk_table_new(10,12,FALSE);
                editfs_label=gtk_label_new("Medicine available with the given id");
                editfs_details=gtk_button_new_with_label("EDIT MEDICINE DETAILS");
                mede_name=m[indexe].medicineName;
                //oa(m[indexe].quantity,mede_qty,10);
    		sprintf(medq,"%d",m[indexe].quantity);
    		mede_qty=medq;
        	sprintf(medp,"%d",m[indexe].price);
        	mede_price=medp;
    		mede_md=m[indexe].Mfg_Date;
    		mede_ed=m[indexe].Exp_Date;
                med_name=gtk_entry_new();
		 med_price=gtk_entry_new();
		 med_quantity=gtk_entry_new();
		 med_md=gtk_entry_new();
		 med_ed=gtk_entry_new();
		 med_namel=gtk_label_new("Medicine name:");
		 med_pricel=gtk_label_new("Medicine price:");
		 med_quantityl=gtk_label_new("Medicine quantity:");
		 med_mdl=gtk_label_new("Medicine MFG date:");
		 med_edl=gtk_label_new("Medicine EXP date:");
		 gtk_entry_set_text(GTK_ENTRY(med_name),mede_name);
		 gtk_entry_set_text(GTK_ENTRY(med_price),mede_price);
		 gtk_entry_set_text(GTK_ENTRY(med_quantity),mede_qty);
		 gtk_entry_set_text(GTK_ENTRY(med_md),mede_md);
		 gtk_entry_set_text(GTK_ENTRY(med_ed),mede_ed);
                gtk_table_attach_defaults(GTK_TABLE(editfs_table),editfs_label,0,2,0,1);
    		gtk_table_attach_defaults(GTK_TABLE(editfs_table),med_namel,0,1,1,2);
    		gtk_table_attach_defaults(GTK_TABLE(editfs_table),med_name,1,2,1,2);
    		gtk_table_attach_defaults(GTK_TABLE(editfs_table),med_pricel,0,1,2,3);
    		gtk_table_attach_defaults(GTK_TABLE(editfs_table),med_price,1,2,2,3);
    		gtk_table_attach_defaults(GTK_TABLE(editfs_table),med_quantityl,0,1,3,4);
    		gtk_table_attach_defaults(GTK_TABLE(editfs_table),med_quantity,1,2,3,4);
    		gtk_table_attach_defaults(GTK_TABLE(editfs_table),med_mdl,0,1,4,5);
    		gtk_table_attach_defaults(GTK_TABLE(editfs_table),med_md,1,2,4,5);
    		gtk_table_attach_defaults(GTK_TABLE(editfs_table),med_edl,0,1,5,6);
    		gtk_table_attach_defaults(GTK_TABLE(editfs_table),med_ed,1,2,5,6);
    		gtk_table_attach_defaults(GTK_TABLE(editfs_table),editfs_details,0,2,6,7);
    		 g_signal_connect(editfs_details,"clicked",G_CALLBACK(edit_medicine_det),med_name);
                gtk_container_add(GTK_CONTAINER(editfs_window),editfs_table);
		gtk_widget_show_all (editfs_window);
		gtk_main ();
        	
        	
        }
}
void edit_medicine_det(){
	const char *medef_name,*medef_md,*medef_ed,*medef_price,*medef_qty;
	medef_name=gtk_entry_get_text(GTK_ENTRY(med_name));
	medef_price=gtk_entry_get_text(GTK_ENTRY(med_price));
	medef_qty=gtk_entry_get_text(GTK_ENTRY(med_quantity));
	medef_md=gtk_entry_get_text(GTK_ENTRY(med_md));
	medef_ed=gtk_entry_get_text(GTK_ENTRY(med_ed));
	strcpy(m[indexe].Mfg_Date,medef_md);
	strcpy(m[indexe].Exp_Date,medef_ed);
	m[indexe].price=atoi(medef_price);
	m[indexe].quantity=atoi(medef_qty);
	file_update();
	gtk_window_close(GTK_WINDOW(edit_window));
	gtk_window_close(GTK_WINDOW(editfs_window));
}
void edit_medicine(){
    edit_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *edit_table;
    GtkWidget *label,*med_details,*edit_med_id,*med_id_label;
    edit_table=gtk_table_new(10,12,FALSE);
    label=gtk_label_new("VVR PHARMACY");
    med_details=gtk_button_new_with_label("GET MEDICINE DETAILS");
    edit_entry_id=gtk_entry_new();
    med_id_label=gtk_label_new("Enter the id of the medicine you want to edit:");
    gtk_table_attach_defaults(GTK_TABLE(edit_table),label,0,2,0,1);
    gtk_table_attach_defaults(GTK_TABLE(edit_table),med_id_label,0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(edit_table),edit_entry_id,1,2,1,2);
    gtk_table_attach_defaults(GTK_TABLE(edit_table),med_details,0,2,2,3);
    g_signal_connect(med_details,"clicked",G_CALLBACK(edit_medicinef),NULL);
    gtk_container_add(GTK_CONTAINER(edit_window),edit_table);
    gtk_widget_show_all(edit_window);
    gtk_main();
}

void delete_medicine(){
    const char *del_med_id;
    del_med_id=gtk_entry_get_text(GTK_ENTRY(del_entry));
    int delete_id,at_index;
    delete_id=atoi(del_med_id);
    at_index=find_medicine_index_id(delete_id);
    for (int a = at_index; a < counter; a++)
    {
        m[a].id=m[a+1].id-1;
        strcpy(m[a].medicineName,m[a+1].medicineName);
        strcpy(m[a].Company,m[a+1].Company);
        m[a].price=m[a+1].price;
        strcpy(m[a].Mfg_Date,m[a+1].Mfg_Date);
        strcpy(m[a].Exp_Date,m[a+1].Exp_Date);
        m[a].quantity=m[a+1].quantity;
    }
    counter--;
    file_update();
}

void delete_button(){
    GtkWidget *del_window;
    del_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *del_table;
    GtkWidget *label,*del_medicine,*del_id;
    del_table=gtk_table_new(8,10,FALSE);
    label=gtk_label_new("VVR PHARMACY");
    del_id=gtk_label_new("Enter the id of the medicine you want to delete:");
    del_medicine=gtk_button_new_with_label("DELETE MEDICINE");
    del_entry=gtk_entry_new();
    gtk_table_attach_defaults(GTK_TABLE(del_table),label,0,2,0,1);
    gtk_table_attach_defaults(GTK_TABLE(del_table),del_id,0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(del_table),del_entry,1,2,1,2);
    gtk_table_attach_defaults(GTK_TABLE(del_table),del_medicine,0,2,2,3);
    g_signal_connect(del_medicine,"clicked",G_CALLBACK(delete_medicine),NULL);
    gtk_container_add(GTK_CONTAINER(del_window),del_table);
    gtk_widget_show_all(del_window);
    gtk_main();
}
struct billing_item cart[10];
int num_of_med=0;
int cost=0;

void customer_billing(){
	num_of_med=0;
	cost=0;
    	GtkWidget *cust_bill_window,*cust_bill_table;
    	GtkWidget *cust_bill_idl;
    	GtkWidget *add_to_cart,*viewcart,*gen_bill;
        cust_bill_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
        cust_bill_table=gtk_table_new(6,6,FALSE);
        add_to_cart=gtk_button_new_with_label("ADD TO CART");
        viewcart=gtk_button_new_with_label("VIEW CART");
        gen_bill=gtk_button_new_with_label("GENERATE BILL");
        cust_bill_idl=gtk_label_new("Enter the id of the medicine you want to buy: ");
        cust_bill_id=gtk_entry_new();
        gtk_table_attach_defaults(GTK_TABLE(cust_bill_table),cust_bill_idl,0,1,0,1);
        gtk_table_attach_defaults(GTK_TABLE(cust_bill_table),cust_bill_id,1,2,0,1);
        gtk_table_attach_defaults(GTK_TABLE(cust_bill_table),add_to_cart,0,2,1,2);
        gtk_table_attach_defaults(GTK_TABLE(cust_bill_table),viewcart,0,2,2,3);
        gtk_table_attach_defaults(GTK_TABLE(cust_bill_table),gen_bill,0,2,3,4);
        g_signal_connect(viewcart,"clicked",G_CALLBACK(view_cart),NULL);
        g_signal_connect(add_to_cart,"clicked",G_CALLBACK(add_cart),NULL);
        g_signal_connect(gen_bill,"clicked",G_CALLBACK(generate_bill),NULL);
        gtk_container_add(GTK_CONTAINER(cust_bill_window),cust_bill_table);
	gtk_widget_show_all (cust_bill_window);
	gtk_main ();
        
}

void add_cart(){
	const char *add_cart_id;
	int add_cart_idf;
	add_cart_id=gtk_entry_get_text(GTK_ENTRY(cust_bill_id));
	add_cart_idf=atoi(add_cart_id);
	indexe=find_medicine_index_id(add_cart_idf);
	if(indexe==-1){
                GtkWidget *findf_label,*findf_table,*findf_window;
                findf_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
                findf_table=gtk_table_new(6,6,FALSE);
                findf_label=gtk_label_new("Medicine not available with the given id");
                gtk_table_attach_defaults(GTK_TABLE(findf_table),findf_label,3,5,4,5);
                gtk_container_add(GTK_CONTAINER(findf_window),findf_table);
		gtk_widget_show_all (findf_window);
		gtk_main ();
            }
        else{
        	GtkWidget *finds_label,*finds_table,*finds_window,*tab_quantityl,*tab_quantitya,*tab_quantityreq,*cont_button;
        	char quantityot[10];
        	sprintf(quantityot,"%d",m[indexe].quantity);
                finds_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
                finds_table=gtk_table_new(6,6,FALSE);
                finds_label=gtk_label_new("Medicine available with the given id");
                tab_quantityl=gtk_label_new("The available quantity of the medicine available is :");
                tab_quantitya=gtk_label_new(quantityot);
                tab_quantityreq=gtk_label_new("Enter the quantity of medicine you want to buy: ");
                tab_quantity=gtk_entry_new();
                cont_button=gtk_button_new_with_label("CONTINUE SHOPPING");
                gtk_table_attach_defaults(GTK_TABLE(finds_table),finds_label,0,1,0,1);
                gtk_table_attach_defaults(GTK_TABLE(finds_table),tab_quantityl,0,1,1,2);
                gtk_table_attach_defaults(GTK_TABLE(finds_table),tab_quantitya,1,2,1,2);
                gtk_table_attach_defaults(GTK_TABLE(finds_table),tab_quantityreq,0,1,2,3);
                gtk_table_attach_defaults(GTK_TABLE(finds_table),tab_quantity,1,2,2,3);
                gtk_table_attach_defaults(GTK_TABLE(finds_table),cont_button,0,2,3,4);
                g_signal_connect(cont_button,"clicked",G_CALLBACK(add_item_to_cart),NULL);
                gtk_container_add(GTK_CONTAINER(finds_window),finds_table);
		gtk_widget_show_all (finds_window);
		gtk_main ();
        }
}
void add_item_to_cart(){
	const char *add_cart_id,*add_cart_qty;
	int add_cart_idf,add_cart_qtyf;
	int indexe;
	add_cart_id=gtk_entry_get_text(GTK_ENTRY(cust_bill_id));
	add_cart_qty=gtk_entry_get_text(GTK_ENTRY(tab_quantity));
	add_cart_idf=atoi(add_cart_id);
	add_cart_qtyf=atoi(add_cart_qty);
	indexe=find_medicine_index_id(add_cart_idf);
	cart[num_of_med].index=indexe;
        cart[num_of_med].med_id=m[indexe].id;
	cart[num_of_med].quantity=add_cart_qtyf;
        cost=cost+(m[indexe].price*add_cart_qtyf);
        m[indexe].quantity-=add_cart_qtyf;
        num_of_med++;
	file_update();
}
void generate_bill(){
	GtkWidget *gen_bill_window;
	gen_bill_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(gen_bill_window), 400, 300);
	GtkWidget *gen_bill_table;
	gen_bill_table=gtk_table_new(num_of_med+2,7,TRUE);
	GtkWidget *medicinenamegb;
        GtkWidget *companygb;
        GtkWidget *Expdategb;
        GtkWidget *pricepergb;
        GtkWidget *pricegb;
        GtkWidget *quantitygb;
        GtkWidget *totalcost;
        GtkWidget *totalcostl;
        char totalcosta[10];
        sprintf(totalcosta,"%d",cost);
        totalcost=gtk_label_new(totalcosta);
        companygb=gtk_label_new("COMPANY");
        medicinenamegb=gtk_label_new("MEDICINE NAME");
        pricepergb=gtk_label_new("PRICE PER TABLET");
        pricegb=gtk_label_new("PRICE");
        quantitygb=gtk_label_new("QUANTITY");
        Expdategb=gtk_label_new("EXP_DATE");
        totalcostl=gtk_label_new("TOTAL COST: ");
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),medicinenamegb,0,1,0,1);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),companygb,1,2,0,1);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),Expdategb,2,3,0,1);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),pricepergb,3,4,0,1);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),quantitygb,4,5,0,1);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),pricegb,5,6,0,1);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),totalcostl,0,4,num_of_med+2,num_of_med+3);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),totalcost,4,6,num_of_med+2,num_of_med+3);
    	for (int j = 0; j < num_of_med; j++)
    	{
        GtkWidget *medicinenamegbt;
        GtkWidget *companygbt;
        GtkWidget *Expdategbt;
        GtkWidget *pricepergbt;
        GtkWidget *pricetgbt;
        GtkWidget *quantitygbtt;
        char pricegbt[10];
        char quantitygbt[10];
        char tpricegbt[10];
        sprintf(pricegbt,"%d",m[cart[j].index].price);
        sprintf(tpricegbt,"%d",cart[j].quantity*m[cart[j].index].price);
        sprintf(quantitygbt,"%d",cart[j].quantity);
        medicinenamegbt=gtk_label_new(m[cart[j].index].medicineName);
        Expdategbt=gtk_label_new(m[cart[j].index].Exp_Date);
        companygbt=gtk_label_new(m[cart[j].index].Company);
     	pricepergbt=gtk_label_new(pricegbt);
     	pricetgbt=gtk_label_new(tpricegbt);
     	quantitygbtt=gtk_label_new(quantitygbt);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),medicinenamegbt,0,1,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),companygbt,1,2,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),Expdategbt,2,3,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),pricepergbt,3,4,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),quantitygbtt,4,5,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(gen_bill_table),pricetgbt,5,6,j+1,j+2);
    	}
    	gtk_container_add(GTK_CONTAINER(gen_bill_window),gen_bill_table);
    	gtk_widget_show_all(gen_bill_window);
    	gtk_main();
}
void view_cart(){
	GtkWidget *view_cart_window;
	view_cart_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(view_cart_window), 400, 300);
	GtkWidget *view_cart_table;
	view_cart_table=gtk_table_new(num_of_med+2,7,TRUE);
	GtkWidget *medicinenamevc;
        GtkWidget *companyvc;
        GtkWidget *Expdatevc;
        GtkWidget *pricepervc;
        GtkWidget *pricevc;
        GtkWidget *quantityvc;
        companyvc=gtk_label_new("COMPANY");
        medicinenamevc=gtk_label_new("MEDICINE NAME");
        pricepervc=gtk_label_new("PRICE PER TABLET");
        pricevc=gtk_label_new("PRICE");
        quantityvc=gtk_label_new("QUANTITY");
        Expdatevc=gtk_label_new("EXP_DATE");
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),medicinenamevc,0,1,0,1);
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),companyvc,1,2,0,1);
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),Expdatevc,2,3,0,1);
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),pricepervc,3,4,0,1);
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),quantityvc,4,5,0,1);
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),pricevc,5,6,0,1);
    	for (int j = 0; j < num_of_med; j++)
    	{
        GtkWidget *medicinenamevct;
        GtkWidget *companyvct;
        GtkWidget *Expdatevct;
        GtkWidget *pricepervct;
        GtkWidget *pricetvct;
        GtkWidget *quantityvctt;
        char pricevct[10];
        char quantityvct[10];
        char tpricevct[10];
        sprintf(pricevct,"%d",m[cart[j].index].price);
        sprintf(tpricevct,"%d",cart[j].quantity*m[cart[j].index].price);
        sprintf(quantityvct,"%d",cart[j].quantity);
        medicinenamevct=gtk_label_new(m[cart[j].index].medicineName);
        Expdatevct=gtk_label_new(m[cart[j].index].Exp_Date);
        companyvct=gtk_label_new(m[cart[j].index].Company);
     	pricepervct=gtk_label_new(pricevct);
     	pricetvct=gtk_label_new(tpricevct);
     	quantityvctt=gtk_label_new(quantityvct);
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),medicinenamevct,0,1,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),companyvct,1,2,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),Expdatevct,2,3,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),pricepervct,3,4,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),quantityvctt,4,5,j+1,j+2);
        gtk_table_attach_defaults(GTK_TABLE(view_cart_table),pricetvct,5,6,j+1,j+2);
    	}
    	gtk_container_add(GTK_CONTAINER(view_cart_window),view_cart_table);
    	gtk_widget_show_all(view_cart_window);
    	gtk_main();
}
int main (int argc, char *argv[])
{
struct_intialization();
gtk_init (&argc, &argv);
GtkWidget *winmain = gtk_window_new (GTK_WINDOW_TOPLEVEL);
GtkWidget *title;
GtkWidget *maintable;
GtkWidget *employee_loginl,*customer_loginl,*employee_loginb,*customer_loginb;
maintable=gtk_table_new(4,5,FALSE);
gtk_window_set_position(GTK_WINDOW(winmain),GTK_WIN_POS_CENTER_ALWAYS);
title=gtk_label_new("WELCOME TO VVR PHARMACY");
employee_loginl=gtk_label_new("Click here to login as an employee");
customer_loginl=gtk_label_new("Click here to login as a customer");
customer_loginb=gtk_button_new_with_label("CUSTOMER LOGIN");
employee_loginb=gtk_button_new_with_label("EMPLOYEE LOGIN");
gtk_table_attach_defaults(GTK_TABLE(maintable),title,0,2,0,1);
gtk_table_attach_defaults(GTK_TABLE(maintable),employee_loginl,0,1,1,2);
gtk_table_attach_defaults(GTK_TABLE(maintable),employee_loginb,1,2,1,2);
gtk_table_attach_defaults(GTK_TABLE(maintable),customer_loginl,0,1,2,3);
gtk_table_attach_defaults(GTK_TABLE(maintable),customer_loginb,1,2,2,3);
g_signal_connect(employee_loginb,"clicked",G_CALLBACK(verify_but_eid),NULL);
g_signal_connect(customer_loginb,"clicked",G_CALLBACK(verify_but_ecid),NULL);
gtk_container_add(GTK_CONTAINER(winmain),maintable);
gtk_widget_show_all(winmain);
gtk_main ();
file_update();
return 0;
}


