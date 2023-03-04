#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

class Attr
{
public:



	virtual bool operator==(const Attr &right)
	{
		return false;
	};


	virtual bool operator!=(const Attr &right)
	{
		return false;
	};


	virtual bool operator<(const Attr &right)
	{
		return false;
	};


	virtual bool operator<=(const Attr &right)
	{
		return false;
	};


	virtual bool operator>=(const Attr &right)
	{
		return false;
	};

	virtual void print()
	{
		cout<<"entered base class"<<endl;
	}

};

class stringAttribute : public Attr
{
private:
	string value;

public:
	stringAttribute()
	{
		cout<<"enter the string value"<<endl;
		cin>>value;
	}

	void print()
	{
		cout<<value;
	}

	bool operator==(const stringAttribute &right)
	{

		if (value == right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const stringAttribute &right)
	{
		if (value == right.value)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator<(const stringAttribute &right)
	{
		if (value < right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<=(const stringAttribute &right)
	{
		if (value <= right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>(const stringAttribute &right)
	{
		if (value > right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(const stringAttribute &right)
	{
		if (value >= right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string getvalue()
	{
		return value;
	}


};


class integerAttribute : public Attr
{
private:
	int value;

public:
	integerAttribute()
	{
		cout<<"enter the integer value"<<endl;
		cin>>value;
	}

	void print()
	{
		cout<<" "<<value;
	}

	bool operator==(const integerAttribute &right)
	{

		if (value == right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const integerAttribute &right)
	{
		if (value == right.value)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator<(const integerAttribute &right)
	{
		if (value < right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<=(const integerAttribute &right)
	{
		if (value <= right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>(const integerAttribute &right)
	{
		if (value > right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(const integerAttribute &right)
	{
		if (value >= right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int getvalue()
	{
		return value;
	}


};


class floatAttribute : public Attr
{
private:
	float value;

public:
	floatAttribute()
	{
		cout<<"enter the float value"<<endl;
		cin>>value;
	}

	void print()
	{
		cout<<value;
	}

	bool operator==(const floatAttribute &right)
	{

		if (value == right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const floatAttribute &right)
	{
		if (value == right.value)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator<(const floatAttribute &right)
	{
		if (value < right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<=(const floatAttribute &right)
	{
		if (value <= right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>(const floatAttribute &right)
	{
		if (value > right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(const floatAttribute &right)
	{
		if (value >= right.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	float getvalue()
	{
		return value;
	}


};

class Record
{
	vector<Attr *> attrptr;
	vector<string> attrnamesrec;//for printing attrnames
	vector<int> attrindsrec;// to get attrinds outside the constructor scope

public:

	Record& operator=(const Record& re)
	{
		attrnamesrec = re.getattrnamesrec();
		attrindsrec = re.getattrindsrec();
		for(auto it=re.getattrptr().begin();it!=attrptr.end();it++)//copying values from give re to the give vector of attr*
			{
				string type;
				type=re.getattrnamesrec();
				auto itcopy = attrptr.begin();
				if(type=="int")
				{
					dynamic_cast<Attr*>(*itcopy) = new integerAttribute;
					(*itcopy)->getvalue() = (*it)->getvalue();

				}else if(type=="string")
				{
					dynamic_cast<Attr*>(*itcopy) = new stringAttribute;
					(*itcopy)->getvalue() = (*it)->getvalue();
				}else if(type=="float")
				{
					dynamic_cast<Attr*>(*itcopy) = new floatAttribute;
					(*itcopy)->getvalue()= (*it)->getvalue();
				}
				itcopy++;
			}
	}

	Record(int nattr, vector<string>attrnames, vector<int>attrinds)
	{
		for(int i = 0; i < attrnames.size(); i++)
		{
			attrnamesrec.push_back(attrnames[i]);	
		}
		for(int i = 0; i < attrinds.size(); i++)
		{
			attrindsrec.push_back(attrinds[i]);	
		}


		for(int i=0;i<nattr;i++)
		{
			string type;
			cout<<"enter the type"<<endl;
			cin>>type;
			if(type=="int")
			{
				attrptr.push_back(new integerAttribute());
			}else if(type=="string")
			{
				attrptr.push_back(new stringAttribute());
			}else if(type=="float")
			{
				attrptr.push_back(new floatAttribute());
			}
		}
	}
	void print_record()
	{
		for(int i=0;i<attrptr.size();i++)
		{
			int j=attrindsrec[i];
			cout<<"attribute name:"<<attrnamesrec[j];
			attrptr[j]->print();
		}
	}

	vector<string> getattrnamesrec()
	{
		return attrnamesrec;
	}
	vector<int> getattrindsrec()
	{
		return attrindsrec;
	}
	vector<Attr*> getattrptr()
	{
		return attrptr;
	}
	//
};

class Relation
{
	int nattr, nrecs;
	vector<int> attrinds;
	vector<string> attrnames;
	list<Record *> recs;
    public:

	Relation& operator=(const Relation&R1)
	{

		nattr = R1.getnattr();
		nrecs = R1.getnrecs();
		attrinds = R1.getattrinds();
		attrnames = R1.getattrnames();
		auto itcopy = recs.begin();
		for(auto it = R1.getrecs().begin(); it != R1.getrecs().end(); it++)
		{
			*itcopy = *it;
			itcopy++;
		}	
	}

	Relation(int nattr,int nrecs,vector<int>attrinds)
	{
		for (int i = 0; i < nattr; i++)
		{
			cout<<"enter attrnames"<<endl;
			string temp;
			cin >> temp;
			attrnames.push_back(temp);
		}

		for (int i = 0; i < nrecs; i++)
		{
			recs.push_back(new Record(nattr,attrnames,attrinds));
		}


	}

	void print_rel()
	{
		for(auto it=recs.begin();it!=recs.end();it++)
		{
		  (*it)->print_record();
		}
	}

	int getnattr()
	{
		return nattr;
	}

	int getnrecs()
	{
		return nrecs;
	}

	int getattrinds()
	{
		return attrinds;
	}

	int getattrnames()
	{
		return attrnames;
	}

	list<Record*>getrecs()
	{
		return recs;
	}

};


Relation *Union(Relation *R1, Relation*R2)
{
	// while((R1->recs[i])&&(R2->recs[i]))
	// {

	// 	i++;
	// }
}


int main()
{
	int nattr=4,nrecs=1;
	vector<int> attrinds;
	attrinds.push_back(2);
	attrinds.push_back(1);
	attrinds.push_back(0);
	attrinds.push_back(3);
	Relation s(nattr, nrecs, attrinds);
	Relation r = s;
    s.print_rel();


}
