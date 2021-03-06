
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/iterator.h"
#include "kernel/object.h"


/**
 * Phalcon\Tag\Select
 *
 * Generates a SELECT html tag using a static array of values or a Phalcon\Mvc\Model resultset
 */
ZEPHIR_INIT_CLASS(Phalcon_Tag_Select) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Tag, Select, phalcon, tag_select, phalcon_tag_select_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Generates a SELECT tag
 *
 * @param array parameters
 * @param array data
 */
PHP_METHOD(Phalcon_Tag_Select, selectField) {

	zend_bool _2$$21;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_9 = NULL, *_13 = NULL;
	zval *parameters, parameters_sub, *data = NULL, data_sub, __$null, params, name, id, value, useEmpty, code, emptyValue, emptyText, options, using, _3, _5, _0$$5, _6$$23, _7$$23, _8$$24, _10$$24, _11$$24, _12$$26, _14$$26, _15$$26;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&useEmpty);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&emptyValue);
	ZVAL_UNDEF(&emptyText);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&using);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_6$$23);
	ZVAL_UNDEF(&_7$$23);
	ZVAL_UNDEF(&_8$$24);
	ZVAL_UNDEF(&_10$$24);
	ZVAL_UNDEF(&_11$$24);
	ZVAL_UNDEF(&_12$$26);
	ZVAL_UNDEF(&_14$$26);
	ZVAL_UNDEF(&_15$$26);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&params, parameters);
		zephir_array_fast_append(&params, data);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_OBS_VAR(&id);
	if (!(zephir_array_isset_long_fetch(&id, &params, 0, 0 TSRMLS_CC))) {
		zephir_array_fetch_string(&_0$$5, &params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/tag/select.zep", 52 TSRMLS_CC);
		zephir_array_update_long(&params, 0, &_0$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	if (!(zephir_memnstr_str(&id, SL("["), "phalcon/tag/select.zep", 58))) {
		if (!(zephir_array_isset_string(&params, SL("id")))) {
			zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_VAR(&name);
	if (!(zephir_array_isset_string_fetch(&name, &params, SL("name"), 0))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		if (!(zephir_is_true(&name))) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_string_fetch(&value, &params, SL("value"), 0))) {
		ZEPHIR_CALL_CE_STATIC(&value, phalcon_tag_ce, "getvalue", &_1, 0, &id, &params);
		zephir_check_call_status();
	} else {
		zephir_array_unset_string(&params, SL("value"), PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&useEmpty);
	if (zephir_array_isset_string_fetch(&useEmpty, &params, SL("useEmpty"), 0)) {
		ZEPHIR_OBS_VAR(&emptyValue);
		if (!(zephir_array_isset_string_fetch(&emptyValue, &params, SL("emptyValue"), 0))) {
			ZEPHIR_INIT_NVAR(&emptyValue);
			ZVAL_STRING(&emptyValue, "");
		} else {
			zephir_array_unset_string(&params, SL("emptyValue"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&emptyText);
		if (!(zephir_array_isset_string_fetch(&emptyText, &params, SL("emptyText"), 0))) {
			ZEPHIR_INIT_NVAR(&emptyText);
			ZVAL_STRING(&emptyText, "Choose...");
		} else {
			zephir_array_unset_string(&params, SL("emptyText"), PH_SEPARATE);
		}
		zephir_array_unset_string(&params, SL("useEmpty"), PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&options);
	if (!(zephir_array_isset_long_fetch(&options, &params, 1, 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(&options, data);
	}
	if (Z_TYPE_P(&options) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(&using);
		if (!(zephir_array_isset_string_fetch(&using, &params, SL("using"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter is required", "phalcon/tag/select.zep", 105);
			return;
		} else {
			_2$$21 = Z_TYPE_P(&using) != IS_ARRAY;
			if (_2$$21) {
				_2$$21 = Z_TYPE_P(&using) != IS_OBJECT;
			}
			if (_2$$21) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter should be an array", "phalcon/tag/select.zep", 108);
				return;
			}
		}
	}
	zephir_array_unset_string(&params, SL("using"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "<select");
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_tag_ce, "renderattributes", &_4, 0, &_5, &params);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	ZEPHIR_GET_CONSTANT(&_5, "PHP_EOL");
	ZEPHIR_INIT_VAR(&code);
	ZEPHIR_CONCAT_VSV(&code, &_3, ">", &_5);
	if (zephir_is_true(&useEmpty)) {
		ZEPHIR_INIT_VAR(&_6$$23);
		ZEPHIR_GET_CONSTANT(&_6$$23, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_7$$23);
		ZEPHIR_CONCAT_SVSVSV(&_7$$23, "\t<option value=\"", &emptyValue, "\">", &emptyText, "</option>", &_6$$23);
		zephir_concat_self(&code, &_7$$23 TSRMLS_CC);
	}
	if (Z_TYPE_P(&options) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_10$$24);
		ZEPHIR_GET_CONSTANT(&_10$$24, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_11$$24);
		ZEPHIR_CONCAT_SV(&_11$$24, "</option>", &_10$$24);
		ZEPHIR_CALL_SELF(&_8$$24, "_optionsfromresultset", &_9, 417, &options, &using, &value, &_11$$24);
		zephir_check_call_status();
		zephir_concat_self(&code, &_8$$24 TSRMLS_CC);
	} else {
		if (Z_TYPE_P(&options) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_14$$26);
			ZEPHIR_GET_CONSTANT(&_14$$26, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_15$$26);
			ZEPHIR_CONCAT_SV(&_15$$26, "</option>", &_14$$26);
			ZEPHIR_CALL_SELF(&_12$$26, "_optionsfromarray", &_13, 418, &options, &value, &_15$$26);
			zephir_check_call_status();
			zephir_concat_self(&code, &_12$$26 TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Invalid data provided to SELECT helper", "phalcon/tag/select.zep", 139);
			return;
		}
	}
	zephir_concat_self_str(&code, SL("</select>") TSRMLS_CC);
	RETURN_CCTOR(&code);

}

/**
 * Generate the OPTION tags based on a resultset
 *
 * @param \Phalcon\Mvc\Model\Resultset resultset
 * @param array using
 * @param mixed value
 * @param string closeOption
 */
PHP_METHOD(Phalcon_Tag_Select, _optionsFromResultset) {

	zval _8$$16, _9$$16;
	zend_object_iterator *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_5 = NULL;
	zval *resultset, resultset_sub, *using, using_sub, *value, value_sub, *closeOption, closeOption_sub, code, params, option, usingZero, usingOne, escaper, optionValue, optionText, strValue, strOptionValue, _0, _3$$6, _6$$14, _7$$15, _10$$17, _11$$18, _12$$20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resultset_sub);
	ZVAL_UNDEF(&using_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&closeOption_sub);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&usingZero);
	ZVAL_UNDEF(&usingOne);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&strValue);
	ZVAL_UNDEF(&strOptionValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_7$$15);
	ZVAL_UNDEF(&_10$$17);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_12$$20);
	ZVAL_UNDEF(&_8$$16);
	ZVAL_UNDEF(&_9$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &resultset, &using, &value, &closeOption);



	ZEPHIR_INIT_VAR(&code);
	ZVAL_STRING(&code, "");
	ZEPHIR_INIT_VAR(&params);
	ZVAL_NULL(&params);
	if (Z_TYPE_P(using) == IS_ARRAY) {
		if (zephir_fast_count_int(using TSRMLS_CC) != 2) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Parameter 'using' requires two values", "phalcon/tag/select.zep", 166);
			return;
		}
		ZEPHIR_OBS_VAR(&usingZero);
		zephir_array_fetch_long(&usingZero, using, 0, PH_NOISY, "phalcon/tag/select.zep", 168 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&usingOne);
		zephir_array_fetch_long(&usingOne, using, 1, PH_NOISY, "phalcon/tag/select.zep", 168 TSRMLS_CC);
	}
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_tag_ce, "getescaperservice", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&escaper, &_0);
	_2 = zephir_get_iterator(resultset TSRMLS_CC);
	_2->funcs->rewind(_2 TSRMLS_CC);
	for (;_2->funcs->valid(_2 TSRMLS_CC) == SUCCESS && !EG(exception); _2->funcs->move_forward(_2 TSRMLS_CC)) {
		{
			ZEPHIR_ITERATOR_COPY(&option, _2);
		}
		if (Z_TYPE_P(using) == IS_ARRAY) {
			if (Z_TYPE_P(&option) == IS_OBJECT) {
				if ((zephir_method_exists_ex(&option, SL("readattribute") TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&optionValue, &option, "readattribute", NULL, 0, &usingZero);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&optionText, &option, "readattribute", NULL, 0, &usingOne);
					zephir_check_call_status();
				} else {
					ZEPHIR_OBS_NVAR(&optionValue);
					zephir_read_property(&optionValue, &option, SL("usingZero"), PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(&optionText);
					zephir_read_property(&optionText, &option, SL("usingOne"), PH_NOISY_CC);
				}
			} else {
				if (Z_TYPE_P(&option) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&optionValue);
					zephir_array_fetch(&optionValue, &option, &usingZero, PH_NOISY, "phalcon/tag/select.zep", 187 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&optionText);
					zephir_array_fetch(&optionText, &option, &usingOne, PH_NOISY, "phalcon/tag/select.zep", 188 TSRMLS_CC);
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Resultset returned an invalid value", "phalcon/tag/select.zep", 190);
					return;
				}
			}
			ZEPHIR_CALL_METHOD(&_3$$6, &escaper, "escapehtmlattr", &_4, 0, &optionValue);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&optionValue, &_3$$6);
			ZEPHIR_CALL_METHOD(&_3$$6, &escaper, "escapehtml", &_5, 0, &optionText);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&optionText, &_3$$6);
			if (Z_TYPE_P(value) == IS_ARRAY) {
				if (zephir_fast_in_array(&optionValue, value TSRMLS_CC)) {
					ZEPHIR_INIT_LNVAR(_6$$14);
					ZEPHIR_CONCAT_SVSVV(&_6$$14, "\t<option selected=\"selected\" value=\"", &optionValue, "\">", &optionText, closeOption);
					zephir_concat_self(&code, &_6$$14 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_7$$15);
					ZEPHIR_CONCAT_SVSVV(&_7$$15, "\t<option value=\"", &optionValue, "\">", &optionText, closeOption);
					zephir_concat_self(&code, &_7$$15 TSRMLS_CC);
				}
			} else {
				zephir_get_strval(&_8$$16, &optionValue);
				ZEPHIR_CPY_WRT(&strOptionValue, &_8$$16);
				zephir_get_strval(&_9$$16, value);
				ZEPHIR_CPY_WRT(&strValue, &_9$$16);
				if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
					ZEPHIR_INIT_LNVAR(_10$$17);
					ZEPHIR_CONCAT_SVSVV(&_10$$17, "\t<option selected=\"selected\" value=\"", &strOptionValue, "\">", &optionText, closeOption);
					zephir_concat_self(&code, &_10$$17 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_11$$18);
					ZEPHIR_CONCAT_SVSVV(&_11$$18, "\t<option value=\"", &strOptionValue, "\">", &optionText, closeOption);
					zephir_concat_self(&code, &_11$$18 TSRMLS_CC);
				}
			}
		} else {
			if (Z_TYPE_P(using) == IS_OBJECT) {
				if (Z_TYPE_P(&params) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&params);
					array_init(&params);
				}
				zephir_array_update_long(&params, 0, &option, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				ZEPHIR_INIT_NVAR(&_12$$20);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_12$$20, using, &params);
				zephir_check_call_status();
				zephir_concat_self(&code, &_12$$20 TSRMLS_CC);
			}
		}
	}
	zend_iterator_dtor(_2);
	RETURN_CCTOR(&code);

}

/**
 * Generate the OPTION tags based on an array
 *
 * @param array data
 * @param mixed value
 * @param string closeOption
 */
PHP_METHOD(Phalcon_Tag_Select, _optionsFromArray) {

	zval _11$$8, _12$$8;
	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	zval *data, data_sub, *value, value_sub, *closeOption, closeOption_sub, strValue, strOptionValue, code, optionValue, optionText, escaped, *_0, _4$$4, _5$$4, _7$$4, _8$$4, _9$$6, _10$$7, _13$$9, _14$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&closeOption_sub);
	ZVAL_UNDEF(&strValue);
	ZVAL_UNDEF(&strOptionValue);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&escaped);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data, &value, &closeOption);



	ZEPHIR_INIT_VAR(&code);
	ZVAL_STRING(&code, "");
	zephir_is_iterable(data, 0, "phalcon/tag/select.zep", 274);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&optionValue);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&optionValue, _2);
		} else {
			ZVAL_LONG(&optionValue, _1);
		}
		ZEPHIR_INIT_NVAR(&optionText);
		ZVAL_COPY(&optionText, _0);
		ZEPHIR_CALL_FUNCTION(&escaped, "htmlspecialchars", &_3, 183, &optionValue);
		zephir_check_call_status();
		if (Z_TYPE_P(&optionText) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZEPHIR_GET_CONSTANT(&_4$$4, "PHP_EOL");
			ZEPHIR_CALL_SELF(&_5$$4, "_optionsfromarray", &_6, 418, &optionText, value, closeOption);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZEPHIR_GET_CONSTANT(&_7$$4, "PHP_EOL");
			ZEPHIR_INIT_LNVAR(_8$$4);
			ZEPHIR_CONCAT_SVSVVSV(&_8$$4, "\t<optgroup label=\"", &escaped, "\">", &_4$$4, &_5$$4, "\t</optgroup>", &_7$$4);
			zephir_concat_self(&code, &_8$$4 TSRMLS_CC);
			continue;
		}
		if (Z_TYPE_P(value) == IS_ARRAY) {
			if (zephir_fast_in_array(&optionValue, value TSRMLS_CC)) {
				ZEPHIR_INIT_LNVAR(_9$$6);
				ZEPHIR_CONCAT_SVSVV(&_9$$6, "\t<option selected=\"selected\" value=\"", &escaped, "\">", &optionText, closeOption);
				zephir_concat_self(&code, &_9$$6 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_10$$7);
				ZEPHIR_CONCAT_SVSVV(&_10$$7, "\t<option value=\"", &escaped, "\">", &optionText, closeOption);
				zephir_concat_self(&code, &_10$$7 TSRMLS_CC);
			}
		} else {
			zephir_get_strval(&_11$$8, &optionValue);
			ZEPHIR_CPY_WRT(&strOptionValue, &_11$$8);
			zephir_get_strval(&_12$$8, value);
			ZEPHIR_CPY_WRT(&strValue, &_12$$8);
			if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
				ZEPHIR_INIT_LNVAR(_13$$9);
				ZEPHIR_CONCAT_SVSVV(&_13$$9, "\t<option selected=\"selected\" value=\"", &escaped, "\">", &optionText, closeOption);
				zephir_concat_self(&code, &_13$$9 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_14$$10);
				ZEPHIR_CONCAT_SVSVV(&_14$$10, "\t<option value=\"", &escaped, "\">", &optionText, closeOption);
				zephir_concat_self(&code, &_14$$10 TSRMLS_CC);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&optionText);
	ZEPHIR_INIT_NVAR(&optionValue);
	RETURN_CCTOR(&code);

}

