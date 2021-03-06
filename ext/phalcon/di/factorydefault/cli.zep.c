
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Phalcon\Di\FactoryDefault\Cli
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework.
 * Thanks to this, the developer does not need to register each service individually.
 * This class is specially suitable for CLI applications
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_FactoryDefault_Cli) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Di\\FactoryDefault, Cli, phalcon, di_factorydefault_cli, phalcon_di_factorydefault_ce, phalcon_di_factorydefault_cli_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Di\FactoryDefault\Cli constructor
 */
PHP_METHOD(Phalcon_Di_FactoryDefault_Cli, __construct) {

	zval _2, _3, _4, _5;
	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_di_factorydefault_cli_ce, getThis(), "__construct", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 10, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "router");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Cli\\Router");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 64, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("router"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "dispatcher");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Cli\\Dispatcher");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 64, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("dispatcher"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "modelsManager");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Mvc\\Model\\Manager");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 64, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "modelsMetadata");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Mvc\\Model\\MetaData\\Memory");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 64, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsMetadata"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "filter");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Filter");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 64, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("filter"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "escaper");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Escaper");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 64, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("escaper"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "annotations");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Annotations\\Adapter\\Memory");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 64, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("annotations"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "security");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Security");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 64, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("security"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "eventsManager");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Events\\Manager");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 64, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("eventsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "transactionManager");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Mvc\\Model\\Transaction\\Manager");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 64, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("transactionManager"), &_2, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("_services"), &_1);
	ZEPHIR_MM_RESTORE();

}

